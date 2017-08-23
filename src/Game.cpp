#include "Game.h"
#include "FBG_Platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <thread>

int Game::init(const char* appID)
{
  auto initializeResult = fbg_PlatformInitializeWindows(appID);
  if (initializeResult != fbgPlatformInitialize_Success)
  {
    return 1;
  }

	int countAppRequestIDs = fbg_AppRequestRecipient_GetNumberRequestIDs();

	if (countAppRequestIDs > 0) {
		printf("Received app request ids:\n");
		for (int i = 0; i < countAppRequestIDs; i++) {
			char buffer[512];
			fbg_AppRequestRecipient_GetRequestIDAtIndex(buffer, 512, i);
			printf("App Request ID %d: %s", i, buffer);
		}
	}

  printf("Press h for list of commands.\nCommand > ");

  return 0;
}

void Game::gameLoop()
{
  while (!exitGame)
  {
    checkKeyboard();
    pumpFBGMessages();
  }
}

void Game::checkKeyboard()
{

  if (_kbhit())
  {
    int key = _getch();

    switch (key) {
    case BACKSPACE_KEY:
      if (commandIndex > 0)
      {
        commandIndex--;
        commandBuffer[commandIndex] = '\0';
        printf("%c %c", key, key);
      }
      break;
    case ENTER_KEY:
      commandBuffer[commandIndex] = '\0';
      printf("\n");
      processCommand();
      break;

    default:
      if (commandIndex < BUFFER_SIZE)
      {
        commandBuffer[commandIndex] = key;
        printf("%c", key);
        commandIndex++;
      }
      break;
    }
  }
}

void Game::processCommand()
{
  char *command = nullptr;
  char *param1 = nullptr;
  char *param2 = nullptr;
  char *param3 = nullptr;

  char *nextToken = nullptr;
  char seps[] = " ";

  // Grab the command parameters
  command = strtok_s(commandBuffer, seps, &nextToken);
  param1 = strtok_s(NULL, seps, &nextToken);

  if (command) {
    switch (command[0])
    {
    case 'h':
      outputCommands();
      break;
    case 'l':
      loginWithScopes();
      break;
    case 'f':
      fbg_FeedShare(
        nullptr,
        "https://www.facebook.com",
        "Testing Link Name",
        "Testing Link Caption",
        "Testing Link Description",
        "http://www.pamperedpetz.net/wp-content/uploads/2015/09/Puppy1.jpg",
        nullptr
      );
      break;
    case 'p':
      fbg_PurchaseIAP(
        param1,
        1,
        1,
        1,
        nullptr,
        nullptr,
        nullptr
      );
      break;
    case 'u':
      fbg_PurchaseIAPWithProductURL(
        "https://friendsmash-unity.herokuapp.com/payments/100coins.php",
        1,
        1,
        1,
        nullptr,
        nullptr,
        nullptr
      );
    case 'v':
      fbg_PayPremium();
      break;
    case 'b':
      fbg_HasLicense();
      break;
    case 'a':
      fbg_AppRequest(
        "Try out this game!",
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        3,
        nullptr,
        nullptr
      );
      break;
		case 'c':
			fbg_AppRequestWithPreSendCallback(
				"Try out this game!",
				nullptr,
				nullptr,
				nullptr,
				nullptr,
				nullptr,
				3,
				nullptr,
				nullptr
			);
			break;
    case 'q':
      exitGame = true;
      break;
    case 'w':
      printf(
        "Is Logged In: %d\n",
        fbg_IsLoggedIn()
      );
      break;
		case 'e': {
			auto formDataHandle = fbg_FormData_CreateNew();
			fbg_FormData_Set(formDataHandle, "abc", 3, "def", 3);
			fbg_FormData_Set(formDataHandle, "ghi", 3, "jkl", 3);
			fbg_LogAppEventWithValueToSum(
				"libfbgplatform",
				formDataHandle,
				1
			);
			break;
		}
		case 'r':
			fbg_ActivateApp();
			break;
		case 'o':
			fbg_FetchOVRAccessToken();
			break;
    default:
      printf("Invalid Command\n");
      break;
    }

    memset(commandBuffer, 0, sizeof(char)*BUFFER_SIZE);
    commandIndex = 0;
  }

  printf("Command > ");
}

void Game::loginWithScopes() {

  fbgLoginScope loginScopes[2] = { fbgLoginScope::user_friends, fbgLoginScope::email };
  fbg_Login_WithScopes(
    2,
    loginScopes
  );
}

void Game::pumpFBGMessages()
{
  fbgMessageHandle message = nullptr;

  while ((message = fbg_PopMessage()) != nullptr) {
    switch (fbg_Message_GetType(message)) {
    case fbgMessage_AccessToken: {
      auto accessTokenHandle = fbg_Message_AccessToken(message);

			if (handleCancelledOrError((fbgResponseHandle)accessTokenHandle, "Access Token")) {
				break;
			}

      auto isValid = fbg_AccessToken_IsValid(accessTokenHandle);
      if (!isValid) {
        // user not logged in
        break;
      }

      auto userid = fbg_AccessToken_GetUserID(accessTokenHandle);

      char token_string[512];
      auto size = fbg_AccessToken_GetTokenString(accessTokenHandle, token_string, 512);
      auto expiration_timestamp = fbg_AccessToken_GetExpirationTimestamp(accessTokenHandle);

      fbgLoginScope permissions[512];
      auto permissionCount = fbg_AccessToken_GetPermissions(accessTokenHandle, permissions, 512);

      printf(
          "User ID: %lld\nAccess Token: %s\nExpiration Timestamp: %lld, Permission Count: %u\nPermissions: ",
          (long long)userid,
          token_string,
          (long long)expiration_timestamp,
          static_cast<uint32_t>(permissionCount)
      );

      for (size_t i = 0; i < permissionCount; i++) {
        printf("%s", fbgLoginScope_ToString(permissions[i]));
      }
      printf("\n");
      break;
    }
    case fbgMessage_FeedShare: {
      auto feedShareHandle = fbg_Message_FeedShare(message);

			if (handleCancelledOrError((fbgResponseHandle)feedShareHandle, "Feed Share")) {
				break;
			}

      auto postId = fbg_FeedShare_GetPostID(feedShareHandle);
      printf(
        "Feed Share Post ID: %ld\n",
        (long)postId
      );
    }
      break;
    case fbgMessage_Purchase: {
      auto payHandle = fbg_Message_Purchase(message);

			if (handleCancelledOrError((fbgResponseHandle)payHandle, "Purchase")) {
				break;
			}

      size_t size;
      char paymentId[512];
      size = fbg_Purchase_GetPaymentID(payHandle, paymentId, 512);

      auto amount = fbg_Purchase_GetAmount(payHandle);

      char currency[512];
      size = fbg_Purchase_GetCurrency(payHandle, currency, 512);

      auto purchaseTime = fbg_Purchase_GetPurchaseTime(payHandle);

      char productId[512];
      size = fbg_Purchase_GetProductId(payHandle, productId, 512);

      char purchaseToken[512];
      size = fbg_Purchase_GetPurchaseToken(payHandle, purchaseToken, 512);

      auto quantity = fbg_Purchase_GetQuantity(payHandle);

      char requestId[512];
      size = fbg_Purchase_GetRequestId(payHandle, requestId, 512);

      char status[512];
      size = fbg_Purchase_GetStatus(payHandle, status, 512);

      char signedRequest[512];
      size = fbg_Purchase_GetSignedRequest(payHandle, signedRequest, 512);

      auto errorCode = fbg_Purchase_GetErrorCode(payHandle);

      char errorMessage[512];
      size = fbg_Purchase_GetErrorMessage(payHandle, errorMessage, 512);

      printf(
        "Purchase Handle: %s\nAmount: %d\nCurrency: %s\nPurchase Time: %lld\n"
        "Product Id:%s\nPurchase Token: %s\nQuantity: %d\nRequest Id: %s\n"
        "Status: %s\nSignedRequest: %s\nError Code: %lld\nErrorMessage: %s\n",
        paymentId,
        (int)amount,
        currency,
        (long long)purchaseTime,
        productId,
        purchaseToken,
        (int)quantity,
        requestId,
        status,
        signedRequest,
        (long long)errorCode,
        errorMessage
      );
      break;
    }
    case fbgMessage_HasLicense: {
      auto hasLicenseHandle = fbg_Message_HasLicense(message);

			if (handleCancelledOrError((fbgResponseHandle)hasLicenseHandle, "Has License")) {
				break;
			}

      auto hasLicense = fbg_HasLicense_GetHasLicense(hasLicenseHandle);
      printf(
        "Has License: %lld",
        hasLicense
      );
      break;
    }
    case fbgMessage_AppRequest: {
      auto appRequestHandle = fbg_Message_AppRequest(message);

			if (handleCancelledOrError((fbgResponseHandle)appRequestHandle, "App Request")) {
				break;
			}
			
      size_t size;
      char requestObjectId[512];
      size = fbg_AppRequest_GetRequestObjectId(
        appRequestHandle,
        requestObjectId,
        512
      );

      char to[512];
      size = fbg_AppRequest_GetTo(appRequestHandle, to, 512);
      printf(
        "Request Object Id: %s\nTo: %s",
        requestObjectId,
        to
      );

			bool hasBeenSent = fbg_AppRequest_HasBeenSent(appRequestHandle);
			if (!hasBeenSent) {
				printf("App request has not been sent.\n");
				fbg_AppRequest_Send(appRequestHandle);
			}
      break;
    }
		case fbgMessage_OVRAccessToken: {
			auto ovrAccessTokenHandle = fbg_Message_OVRAccessToken(message);

			if (handleCancelledOrError((fbgResponseHandle)ovrAccessTokenHandle, "Fetch OVR Access Token")) {
				break;
			}

			char ovrAccessToken[512];
			auto size = fbg_OVRAccessToken_GetTokenString(ovrAccessTokenHandle, ovrAccessToken, 512);
			printf("OVR Access Token: %s\n", ovrAccessToken);

			auto numAccounts = fbg_OVRAccessToken_GetNumberOfAccounts(ovrAccessTokenHandle);
			for (size_t i = 0; i < numAccounts; i++) {
				auto accountType = fbg_OVRAccessToken_GetAccountType(ovrAccessTokenHandle, i);

				char id[512];
				fbg_OVRAccessToken_GetAccountID(ovrAccessTokenHandle, i, id, 512);

				char accountAccessToken[512];
				fbg_OVRAccessToken_GetAccountAccessTokenString(ovrAccessTokenHandle, i, accountAccessToken, 512);

				printf("OVR Account %u:\nAccount Type: %d\nID: %s\nAccess Token: %s\n", static_cast<uint32_t>(i), accountType, id, accountAccessToken);
			}

			break;
		}
    default:
      fprintf(stderr, "unknown message %d", fbg_Message_GetType(message));
    }
    fbg_FreeMessage(message);
  }
}

bool Game::handleCancelledOrError(const fbgResponseHandle obj, const char* messageType)
{
	bool cancelled = fbg_Error_IsResponseCancelled(obj);
	if (cancelled) {
		printf("%s was cancelled\n", messageType);
		return true;
	}

	bool error = fbg_Error_IsResponseError(obj);
	if (error) {
		char errorMessage[512];
		fbg_Error_GetErrorMessage(obj, errorMessage, 512);
		printf("%s Error: %s\n", messageType, errorMessage);
		return true;
	}

	return false;
}

void Game::outputCommands()
{
  printf("\nList of Commands\n----------------\n"
    "h - list commands\n"
    "l - Login (fbg_Login)\n"
    "f - Feed Share (fbg_FeedShare)\n"
    "p - Purchase IAP (fbg_PurchaseIAP)\n"
    "v - Pay Premium (fbg_PayPremium)\n"
    "b - Has License (fbg_HasLicense)\n"
    "a - App Request (fbg_AppRequest)\n"
		"c - App Request With Pre-Send Callback (fbg_AppRequestWithPreSendCallback)\n"
    "w - Is Logged In (fbg_IsLoggedIn)\n"
		"e - App Event (fbg_LogAppEventWithValueToSum)\n"
		"r - Actiate App (fbg_ActivateApp()\n"
		"o - Fetch OVR Access Token (fbg_FetchOVRAccessToken)\n"
    "q - quit\n\n");
}
