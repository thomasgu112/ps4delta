
// Copyright (C) 2019 Force67

// This file was generated on Sat Sep  7 22:01:26 2019

#include "../../ModuleLinker.h"

#include "libSceNpManager.h"

static const mlink::FunctionInfo functions[] = {
	{0xA472E39ED634A6C8, &scec__sceNpIpcCreateMemoryFromKernel},
	{0x51D8509B1EB8FEE3, &scec__sceNpIpcCreateMemoryFromPool},
	{0x872BB27BEF3CB8FA, &scec__sceNpIpcDestroyMemory},
	{0x558F178E2F5C0050, &scec__sceNpIpcFreeImpl},
	{0x577F277C9C176218, &scec__sceNpIpcGetNpMemAllocator},
	{0x54166D7059FBF9A6, &scec__sceNpIpcMallocImpl},
	{0x4F20020310C7DD4C, &scec__sceNpIpcReallocImpl},
	{0x7C71A14B7B8FE769, &scec__sceNpManagerCreateMemoryFromKernel},
	{0xBFCFB6E47F56217E, &scec__sceNpManagerCreateMemoryFromPool},
	{0xE2E86054D02A89A8, &scec__sceNpManagerDestroyMemory},
	{0xF095FF4B60037A7E, &scec__sceNpManagerFreeImpl},
	{0xBA411E3A2CC29085, &scec__sceNpManagerGetNpMemAllocator},
	{0xA744DF09D3C472C9, &scec__sceNpManagerMallocImpl},
	{0x3C8604153D621B46, &scec__sceNpManagerReallocImpl},
	{0xFD096B0FADA958C1, &scec__ZN3sce2np10NpOnlineId5ClearEv},
	{0x80FBB1FB407937D2, &scec__ZN3sce2np10NpOnlineIdC2ERKS1_},
	{0x8017A27DCDBB9CEE, &scec__ZN3sce2np10NpOnlineIdC2Ev},
	{0x914B0AE99B6AA1F3, &scec__ZN3sce2np10NpOnlineIdD0Ev},
	{0x61C30AB2AA0C06D8, &scec__ZN3sce2np10NpOnlineIdD2Ev},
	{0x61DED5EE53386D20, &scec__ZN3sce2np11NpHttpTransD0Ev},
	{0x0F9A899B032571C2, &scec__ZN3sce2np11NpHttpTransD2Ev},
	{0x1636CB672F79B6CE, &scec__ZN3sce2np12NpHttpClientD0Ev},
	{0xF547B0E9BF4FA7C5, &scec__ZN3sce2np12NpHttpClientD2Ev},
	{0xDA5CD6CB6C669E16, &scec__ZN3sce2np13NpAccessTokenC2Ev},
	{0x4856586C7EDE3A79, &scec__ZN3sce2np13NpAccessTokenD0Ev},
	{0xBBDB41892367BE7F, &scec__ZN3sce2np13NpAccessTokenD2Ev},
	{0x6F0C2CA55812E214, &scec__ZN3sce2np4User7GetUserEiPS1_},
	{0x8B6286CA4A1103FE, &scec__ZN3sce2np4UserC2Ei},
	{0x62F2F40FC560E953, &scec__ZN3sce2np4UserC2ERKS1_},
	{0x17F02415AF5C0012, &scec__ZN3sce2np4UserC2Ev},
	{0x1E1290A1D1F5EB89, &scec__ZN3sce2np4UserD0Ev},
	{0x8AD06E7372080DA6, &scec__ZN3sce2np4UserD2Ev},
	{0xB5DF0624544E6840, &scec__ZNK3sce2np4User9GetUserIdEv},
	{0x3B32AF4EF8376585, &sceNpAbortRequest},
	{0x70E2E7E40DD9A2A5, &sceNpAsmClientGetNpComInfo2},
	{0x1EDA4656B54B3A50, &sceNpAsmClientGetNpTitleToken},
	{0x4E20BCD7F38A8E98, &sceNpAsmClientGetServiceIdInfo},
	{0xC19CB933A9738A9D, &sceNpAsmClientInitialize},
	{0xDD997C05E3D387D6, &sceNpCheckCallback},
	{0x2442C77F8C4FB9FA, &sceNpCheckCallbackForLib},
	{0xDABB059A519695E4, &sceNpCheckNpAvailability},
	{0xF19D897391AF1832, &sceNpCheckNpAvailabilityA},
	{0x29F199836CBBDE83, &sceNpCheckNpReachability},
	{0xAFA33260992BCB3F, &sceNpCheckPlus},
	{0x7A2A8C0ADF54B212, &sceNpCreateAsyncRequest},
	{0x1A92D00CD28809A7, &sceNpCreateRequest},
	{0x4BB4139FBD8FAC3C, &sceNpDeleteRequest},
	{0x1A1CFD8960D4B42E, &sceNpGetAccountCountry},
	{0x253FADD346B74F10, &sceNpGetAccountCountryA},
	{0xF150537917F56702, &sceNpGetAccountDateOfBirth},
	{0xAB733B5F304A0B7B, &sceNpGetAccountDateOfBirthA},
	{0x6BC47DFFBE6EE223, &sceNpGetAccountId},
	{0xADB9276948E9A96A, &sceNpGetAccountIdA},
	{0x299D4C8FDC841987, &sceNpGetAccountLanguage},
	{0x4CF31B808C6FA20D, &sceNpGetAccountLanguageA},
	{0x20F6F585DD700067, &sceNpGetGamePresenceStatus},
	{0xA0F3BD538D98A602, &sceNpGetGamePresenceStatusA},
	{0xA7FA3BE029E83736, &sceNpGetNpId},
	{0x7BF66E846128782E, &sceNpGetNpReachabilityState},
	{0x5C39DC5D02095129, &sceNpGetOnlineId},
	{0x8A5C0B338CCE9AEE, &sceNpGetParentalControlInfo},
	{0x9BD2F73BACACB7F5, &sceNpGetParentalControlInfoA},
	{0x7901FB9D63DC0207, &sceNpGetState},
	{0x56061CCCF181E6CB, &sceNpGetUserIdByAccountId},
	{0x17A138C9CABD0DB8, &sceNpGetUserIdByOnlineId},
	{0x39A777AEF63F3494, &sceNpHasSignedUp},
	{0x7C9B90BA2A735B5D, &sceNpIdMapperAbortRequest},
	{0x6A534B95EDAF0028, &sceNpIdMapperAccountIdToNpId},
	{0x4D5DCA29764B523E, &sceNpIdMapperAccountIdToOnlineId},
	{0x94201800AE247E47, &sceNpIdMapperCreateRequest},
	{0x67C9F2550086095A, &sceNpIdMapperDeleteRequest},
	{0xDB514CCFA3B80761, &sceNpIdMapperNpIdToAccountId},
	{0xCC466F1B28C486E9, &sceNpIdMapperOnlineIdToAccountId},
	{0x05DCA4A53C2AD9BB, &sceNpInGameMessageAbortHandle},
	{0xB385046B988125D7, &sceNpInGameMessageCreateHandle},
	{0xF9A9EE4B1D9ABC74, &sceNpInGameMessageDeleteHandle},
	{0x1858555294666C71, &sceNpInGameMessageInitialize},
	{0x561D5B8541BA992B, &sceNpInGameMessagePrepare},
	{0x2242FAD85329229A, &sceNpInGameMessagePrepareA},
	{0x38DED27F95C43262, &sceNpInGameMessageSendData},
	{0x3D00C5C5C9EAC6DC, &sceNpInGameMessageSendDataA},
	{0x6CC1B77159949AE9, &sceNpInGameMessageTerminate},
	{0x1AC5A3CD153B0160, &sceNpIntCheckPlus},
	{0x014BB32902308576, &sceNpManagerIntAbortRequest},
	{0x13AAF3170B031701, &sceNpManagerIntAddPlusMemberTypeCallback},
	{0xF7B4407C9721FAA1, &sceNpManagerIntBindOfflineAccountId},
	{0x5E0EDD25E90A7873, &sceNpManagerIntCheckGameNpAvailability},
	{0x8AC367D18C94F377, &sceNpManagerIntCheckGameNpAvailabilityA},
	{0xC97F2A4859A48B27, &sceNpManagerIntClearParentalControlInfoSubAccount},
	{0x419A57A33F708DB1, &sceNpManagerIntClearUsedFlag},
	{0xEA7F0D4F5A475BD8, &sceNpManagerIntCreateLoginContext},
	{0x09D420DFDAA57E06, &sceNpManagerIntCreateLoginRequest},
	{0xC5993E41C8AFAC51, &sceNpManagerIntCreateRequest},
	{0x1209A51C6F774E9C, &sceNpManagerIntDeleteLoginContext},
	{0x1E7782F92A5E2F07, &sceNpManagerIntDeleteRequest},
	{0xEFEB8A08C7B848B9, &sceNpManagerIntGetAccountCountry},
	{0x7E3278C5733EDD3C, &sceNpManagerIntGetAccountCountryA},
	{0x767CAF3D36A6E067, &sceNpManagerIntGetAccountDateOfBirth},
	{0x082A27915C1CEC37, &sceNpManagerIntGetAccountDateOfBirthA},
	{0x5D2FDE63B291AA34, &sceNpManagerIntGetAccountId},
	{0x0BAC6CB510453A2A, &sceNpManagerIntGetAccountLanguage},
	{0x7BAAD38C599C4236, &sceNpManagerIntGetAccountLanguageA},
	{0x1EF36B3219560529, &sceNpManagerIntGetAccountNpEnv},
	{0xF65CF87E44BE7849, &sceNpManagerIntGetAccountType},
	{0x500036FD94E68097, &sceNpManagerIntGetActiveSigninState},
	{0x0680FA76EE7EC31A, &sceNpManagerIntGetAuthorizationCode},
	{0xD43317B84D026C64, &sceNpManagerIntGetAuthorizationCodeA},
	{0xD959A7C52D5A646D, &sceNpManagerIntGetAuthorizationCodeWithRedirectUri},
	{0x1E4520161AE9003E, &sceNpManagerIntGetAuthServerErrorFlag},
	{0x4D7CE90A03E65C44, &sceNpManagerIntGetClientCredentialAccessToken},
	{0x39C9D275D3E4427B, &sceNpManagerIntGetGameTitleBanInfo},
	{0x6ED2907CD7B58C16, &sceNpManagerIntGetGameTitleToken},
	{0x3BB8AF21FF402052, &sceNpManagerIntGetGameTitleTokenA},
	{0xBDF1C13F6FD65DC3, &sceNpManagerIntGetGameVshToken},
	{0x8C22445AE1316D98, &sceNpManagerIntGetLastAccountLanguage},
	{0x39A77E9E8A454D30, &sceNpManagerIntGetMAccountId},
	{0x0534557CEC7B2B57, &sceNpManagerIntGetNpEnv},
	{0x6B312662FE4DA96A, &sceNpManagerIntGetNpId},
	{0xE350953118A78D65, &sceNpManagerIntGetNpIdSdk},
	{0xEF44B0BF0EE1E9C9, &sceNpManagerIntGetOfflineAccountId},
	{0x8E440A5904CEBBC8, &sceNpManagerIntGetOnlineIdInternal},
	{0xB13B6F1784158638, &sceNpManagerIntGetOnlineIdSdk},
	{0x16AB4338752E0CDC, &sceNpManagerIntGetParentalControlFlag},
	{0x352D6C121A23FC1D, &sceNpManagerIntGetParentalControlInfo},
	{0x8208FD426E170EB5, &sceNpManagerIntGetParentalControlInfoA},
	{0x5F9DAF5E756FB691, &sceNpManagerIntGetParentalControlInfoNB},
	{0xBEBADEDCA5BA38F8, &sceNpManagerIntGetPlusMemberType},
	{0x5D115C86A75D1155, &sceNpManagerIntGetPlusMemberTypeNB},
	{0x88396CA3666B41F0, &sceNpManagerIntGetServerError},
	{0xEA689B6BFA5C42DF, &sceNpManagerIntGetSigninState},
	{0xB9501F5A6BFE71CF, &sceNpManagerIntGetTicket},
	{0x3994DE74A3547855, &sceNpManagerIntGetUserIdByAccountId},
	{0x361C72D8D99085BB, &sceNpManagerIntGetUserIdByOfflineAccountId},
	{0xB922E05B3F2885A9, &sceNpManagerIntGetUserIdByOnlineId},
	{0x3CBD743626745CD0, &sceNpManagerIntGetUserList},
	{0x7AD67CE117F752BC, &sceNpManagerIntGetUserNum},
	{0x98A1AA54AD52C059, &sceNpManagerIntGetVshToken},
	{0xD320DDAC882AA631, &sceNpManagerIntGetVshTokenA},
	{0x92853F0EE73517FD, &sceNpManagerIntIsServerMaintenanceError},
	{0xA2CB2FB9779D9EC7, &sceNpManagerIntIsSubAccount},
	{0x6AD807A797508B99, &sceNpManagerIntIsTemporarySignout},
	{0x8F03A3121583E84E, &sceNpManagerIntIsUnregisteredClientError},
	{0x694E50694096FC89, &sceNpManagerIntLoginAddJsonInfo},
	{0x6F37FC6BB2F1B424, &sceNpManagerIntLoginBind},
	{0x5D1A4CF6D41E7025, &sceNpManagerIntLoginCheckSignin},
	{0xC40746440DEE7038, &sceNpManagerIntLoginGet2svInfo},
	{0xFCFD0B1B61141411, &sceNpManagerIntLoginGetAccessToken},
	{0xDFC71F91CCDF374F, &sceNpManagerIntLoginGetAccessTokenViaImplicitFlow},
	{0x76F92A3FD29431F9, &sceNpManagerIntLoginGetAccountId},
	{0x63E84BA9E2EC7919, &sceNpManagerIntLoginGetAuthorizationCode},
	{0x117789F34A74D60B, &sceNpManagerIntLoginGetDeviceCodeInfo},
	{0xCAAB05CBDCA0DAB5, &sceNpManagerIntLoginGetEmail},
	{0xC177C7866CD48CAE, &sceNpManagerIntLoginGetOnlineId},
	{0xC963011E245D11B9, &sceNpManagerIntLoginGetUserId},
	{0xB9A09F1B44C03E68, &sceNpManagerIntLoginParseJsonUserInfo},
	{0xC87974A4F037ACF4, &sceNpManagerIntLoginResetSsoToken},
	{0x86654B222DE94031, &sceNpManagerIntLoginSetAccountInfo},
	{0x5FF5877B109BC5C2, &sceNpManagerIntLoginSetSsoToken},
	{0xAA66471DE8440E88, &sceNpManagerIntLoginValidateCredential},
	{0xCD7BA422D914BA4A, &sceNpManagerIntLoginValidateKratosAuthCode},
	{0xBA3B45C16267BFE1, &sceNpManagerIntLoginVerifyDeviceCode},
	{0x774224595FAEDB98, &sceNpManagerIntPfAuth},
	{0x3DA7D17FEB319F00, &sceNpManagerIntRemovePlusMemberTypeCallback},
	{0x938335C395ECB5C9, &sceNpManagerIntRevalidatePassword},
	{0x3D9873FAF8E9D823, &sceNpManagerIntSetTimeout},
	{0xEB80FA57F00341ED, &sceNpManagerIntSignout},
	{0xC144F870E2B46E3D, &sceNpManagerIntTemporarySignout},
	{0x206E99A0648368C9, &sceNpManagerIntUnbindOfflineAccountId},
	{0xDC5B43EB2E519394, &sceNpManagerIntUpdateVshToken},
	{0xF2433E785CE805AB, &sceNpManagerIntUpdateVshTokenA},
	{0xE80728A9E121B3A1, &sceNpManagerIntWebLoginRequired},
	{0x2C610876020B41E9, &sceNpManagerPrxStartVsh},
	{0xF4FF2A57D5AD80A0, &sceNpManagerPrxStopVsh},
	{0x8948E24C88989D99, &sceNpManagerUtilConvertJidToNpId},
	{0x848197FE1D5C82F0, &sceNpManagerUtilConvertNpIdToJid},
	{0x19AC6BA7711663F3, &sceNpNotifyPlusFeature},
	{0xBAA70F24B58BD3C3, &sceNpPollAsync},
	{0x0E437E581725169B, &sceNpPushInit},
	{0xD52DAEAC5DB8CCD4, &sceNpPushIntBeginInactive},
	{0x5F2BD0BF6AA35278, &sceNpPushIntEndInactive},
	{0x3BFD934E3856C35D, &sceNpPushIntGetConnectionState},
	{0xB8526968A341023E, &sceNpRegisterGamePresenceCallback},
	{0x2ACC312F19387356, &sceNpRegisterGamePresenceCallbackA},
	{0x870E4A36A0007A5B, &sceNpRegisterNpReachabilityStateCallback},
	{0x1889880A787E6E80, &sceNpRegisterPlusEventCallback},
	{0x55F45298F9A3F10F, &sceNpRegisterStateCallback},
	{0xA9025F3BC1C089A6, &sceNpRegisterStateCallbackA},
	{0x2473AD36D43F8E6C, &sceNpServiceClientInit},
	{0x1E19AEF3A6982351, &sceNpServiceClientTerm},
	{0x036090DE4812A294, &sceNpSetContentRestriction},
	{0x28EFB5D5C802ECDD, &sceNpSetGamePresenceOnline},
	{0x0B480D0A24488B85, &sceNpSetGamePresenceOnlineA},
	{0x11CEB7CB9F65F6DC, &sceNpSetNpTitleId},
	{0xFD08250DE46BF03F, &sceNpSetTimeout},
	{0x71120B004BE7FBD3, &sceNpUnregisterNpReachabilityStateCallback},
	{0xC558AA25D0E02A5D, &sceNpUnregisterPlusEventCallback},
	{0x9A38D35E1F8D1D66, &sceNpUnregisterStateCallback},
	{0x337C055DB610B400, &sceNpUnregisterStateCallbackA},
	{0x8F28B9A7D5D6512B, &sceNpWaitAsync},
	{0x0083028CF3D55993, &unk_AIMCjPPVWZM},
	{0x048DD6A364695660, &unk_BI3Wo2RpVmA},
	{0x05003628D66BD87D, &unk_BQA2KNZr2H0},
	{0x08D26851BA956857, &unk_CNJoUbqVaFc},
	{0x0AF1A883AE3EBC29, &unk_CvGog64_vCk},
	{0x0BBED59EC75A28A2, &unk_C77VnsdaKKI},
	{0x0C388A4F21C98AF9, &unk_DDiKTyHJivk},
	{0x0CECC7A08A3E50AF, &unk_DOzHoIo_UK8},
	{0x0E4A70F57FC74950, &unk_Dkpw9X_HSVA},
	{0x0EDDAB11EFDDE5CD, &unk_Dt2rEe_d5c0},
	{0x0EF93EC6A02A5DCA, &unk_Dvk_xqAqXco},
	{0x0F0F320B6AD8A53D, &unk_Dw8yC2rYpT0},
	{0x0F6977AD02BF5734, &unk_D2l3rQK_VzQ},
	{0x0F7B9CA4CB6C984C, &unk_D3ucpMtsmEw},
	{0x10F11430F4FEF572, &unk_EPEUMPT_9XI},
	{0x14CA1251EDD469CE, &unk_FMoSUe3Uac4},
	{0x1640120BD475931E, &unk_FkASC9R1kx4},
	{0x18F451C45334D6BE, &unk_GPRRxFM01r4},
	{0x199D98B67940CC7E, &unk_GZ2YtnlAzH4},
	{0x1AD320C7861C06EA, &unk_GtMgx4YcBuo},
	{0x1AFE1C07C95E65A5, &unk_Gv4cB8leZaU},
	{0x1D287C2096830FBA, &unk_HSh8IJaDD7o},
	{0x1D983C7E0C28AC72, &unk_HZg8fgworHI},
	{0x1E1B6E1007ED56F9, &unk_HhtuEAftVvk},
	{0x1F49F540759D5704, &unk_H0n1QHWdVwQ},
	{0x1F7DC2C2029FE11B, &unk_H33CwgKf4Rs},
	{0x1FAC6A48D5A0D303, &unk_H6xqSNWg0wM},
	{0x2035C58299290EC5, &unk_IDXFgpkpDsU},
	{0x20804189E6181FA3, &unk_IIBBieYYH6M},
	{0x208943695A3B58FE, &unk_IIlDaVo7WP4},
	{0x21C73DF9A45441F4, &unk_Icc9_aRUQfQ},
	{0x2324F8D621BC6277, &unk_IyT41iG8Ync},
	{0x24361B6E071C3C31, &unk_JDYbbgccPDE},
	{0x24BE33CFA7A12161, &unk_JL4zz6ehIWE},
	{0x258A3D10C99A43BB, &unk_JYo9EMmaQ7s},
	{0x26B5C0EDB68130F4, &unk_JrXA7baBMPQ},
	{0x270A53D8B612C6B8, &unk_JwpT2LYSxrg},
	{0x274314C6EA3D1FD7, &unk_J0MUxuo9H9c},
	{0x280D80213A554C28, &unk_KA2AITpVTCg},
	{0x2868AD657B9263B5, &unk_KGitZXuSY7U},
	{0x2A35E955C4176987, &unk_KjXpVcQXaYc},
	{0x2B6A4BF35C5E240D, &unk_K2pL81xeJA0},
	{0x2B707FFE05ACB009, &unk_K3B__gWssAk},
	{0x2CE5AB230EBAF8B4, &unk_LOWrIw66_LQ},
	{0x2E0E6636ACB5CDD4, &unk_Lg5mNqy1zdQ},
	{0x2ED62AC3D336DE1C, &unk_LtYqw9M23hw},
	{0x3037331F74B113D4, &unk_MDczH3SxE9Q},
	{0x3300189271167C05, &unk_MwAYknEWfAU},
	{0x388742300EEF1870, &unk_OIdCMA7vGHA},
	{0x3B8D99941BC83CC3, &unk_O42ZlBvIPMM},
	{0x3FA7E44E8B561448, &unk_P6fkTotWFEg},
	{0x4192797C2D2D3FC3, &unk_QZJ5fC0tP8M},
	{0x41C7E3D88BBB7F75, &unk_Qcfj2Iu7f3U},
	{0x4273BCCCC98A7061, &unk_QnO8zMmKcGE},
	{0x42FA8E90D2B94E15, &unk_QvqOkNK5ThU},
	{0x438F60858A883FCF, &unk_Q49ghYqIP88},
	{0x43B7E7A5D923069D, &unk_Q7fnpdkjBp0},
	{0x4529F30916EAC035, &unk_RSnzCRbqwDU},
	{0x45FA2428732E3AC1, &unk_RfokKHMuOsE},
	{0x49D3626105A353A1, &unk_SdNiYQWjU6E},
	{0x4AE043810B305E0A, &unk_SuBDgQswXgo},
	{0x4AE0820FE019C027, &unk_SuCCD_AZwCc},
	{0x4B2C5D51A903EC75, &unk_SyxdUakD7HU},
	{0x4BB01F7B4965B0BF, &unk_S7Afe0llsL8},
	{0x4BDC43BACD02BA6B, &unk_S9xDus0Cums},
	{0x4C4A062E5660FABD, &unk_TEoGLlZg_r0},
	{0x4C9A928141337B13, &unk_TJqSgUEzexM},
	{0x4ED1C1574987F246, &unk_TtHBV0mH8kY},
	{0x51BBFE7CFE7C5B55, &unk_Ubv_fP58W1U},
	{0x52F0D0ABDF9032E2, &unk_UvDQq9_QMuI},
	{0x531389BC69B2DE60, &unk_UxOJvGmy3mA},
	{0x532507798036D6C8, &unk_UyUHeYA21sg},
	{0x537D0053DD9F59D5, &unk_U30AU92fWdU},
	{0x53D857E6CB27619E, &unk_U9hX5ssnYZ4},
	{0x542603999CA0AEE9, &unk_VCYDmZygruk},
	{0x54690B41C1128799, &unk_VGkLQcESh5k},
	{0x562B234AAE25F80C, &unk_VisjSq4l_Aw},
	{0x5718D7B7C1BFF4DB, &unk_VxjXt8G_9Ns},
	{0x58D1975026DD864A, &unk_WNGXUCbdhko},
	{0x59C7C95D0D8D14FE, &unk_WcfJXQ2NFP4},
	{0x59CDDA0B0601E46A, &unk_Wc3aCwYB5Go},
	{0x5A60395F8C3FE128, &unk_WmA5X4w_4Sg},
	{0x5A86AA8D8D5C704A, &unk_WoaqjY1ccEo},
	{0x5DAD628321E2A1A8, &unk_Xa1igyHioag},
	{0x5DB301F9CD649671, &unk_XbMB_c1klnE},
	{0x5E5184CC2AA51E92, &unk_XlGEzCqlHpI},
	{0x6030C70FA44FE074, &unk_YDDHD6RP4HQ},
	{0x610EFFCF8CC55A89, &unk_YQ7_z4zFWok},
	{0x614FCFC7066ADB55, &unk_YU_PxwZq21U},
	{0x6187CB1CC8B4FB63, &unk_YYfLHMi0_2M},
	{0x61BBBA03157A4B4A, &unk_Ybu6AxV6S0o},
	{0x61E2733AA1C0A625, &unk_YeJzOqHApiU},
	{0x62E75218A42AAA72, &unk_YudSGKQqqnI},
	{0x6397A096ED45AEC1, &unk_Y5eglu1FrsE},
	{0x643A1C22AFB68DB2, &unk_ZDocIq_2jbI},
	{0x6441D55869D8D6F2, &unk_ZEHVWGnY1vI},
	{0x64767A419F311CB1, &unk_ZHZ6QZ8xHLE},
	{0x678C273EB77D8C81, &unk_Z4wnPrd9jIE},
	{0x685A51D95CE64AA0, &unk_aFpR2VzmSqA},
	{0x68967209C1F1CEEE, &unk_aJZyCcHxzu4},
	{0x69068E18854284DE, &unk_aQaOGIVChN4},
	{0x6BB8A92504DF430A, &unk_a7ipJQTfQwo},
	{0x6D9DA606F3FBF5DF, &unk_bZ2mBvP79d8},
	{0x6F59C3B00B03E05A, &unk_b1nDsAsD4Fo},
	{0x70FA28614CE1D42D, &unk_cPooYUzh1C0},
	{0x724CCE7F78A1356B, &unk_ckzOf3ihNWs},
	{0x7284FAAAC539B7D3, &unk_coT6qsU5t9M},
	{0x72E8034011EEC7C9, &unk_cugDQBHux8k},
	{0x72ED4B949A3EE446, &unk_cu1LlJo_5EY},
	{0x750F1B053C243308, &unk_dQ8bBTwkMwg},
	{0x75296498F55372F9, &unk_dSlkmPVTcvk},
	{0x76049688B19B8EE6, &unk_dgSWiLGbjuY},
	{0x77AF795FDEFC060C, &unk_d695X978Bgw},
	{0x77F9EE72B4112598, &unk_d_nucrQRJZg},
	{0x7ACE8E888C4688BD, &unk_es6OiIxGiL0},
	{0x7ECD53096C136020, &unk_fs1TCWwTYCA},
	{0x7ECD816B19AC0198, &unk_fs2BaxmsAZg},
	{0x7F62BC8BB294DB49, &unk_f2K8i7KU20k},
	{0x8050744662A3C9A2, &unk_gFB0RmKjyaI},
	{0x8101724FD688B0E9, &unk_gQFyT9aIsOk},
	{0x813F4B67EA841BF3, &unk_gT9LZ_qEG_M},
	{0x8253B94686A8D3FD, &unk_glO5Roao0_0},
	{0x84814531EA0B85C6, &unk_hIFFMeoLhcY},
	{0x84A4DDAD1D7E74DD, &unk_hKTdrR1_dN0},
	{0x86E27FD86CF3357B, &unk_huJ_2GzzNXs},
	{0x87411E9D7D9E5B20, &unk_h0EenX2eWyA},
	{0x87C777B5F322CA17, &unk_h8d3tfMiyhc},
	{0x882F48FAE6097C0C, &unk_iC9I_uYJfAw},
	{0x891BDA6927C705CF, &unk_iRvaaSfHBc8},
	{0x89DBE4B3303FF888, &unk_idvkszA__Ig},
	{0x8A4F3A7B5C4BA68A, &unk_ik86e1xLpoo},
	{0x8BCD0858ACC6AC21, &unk_i80IWKzGrCE},
	{0x8BD3E57620BDDC38, &unk_i9PldiC93Dg},
	{0x8E3A536347D1038E, &unk_jjpTY0fRA44},
	{0x8F0A74013AD633EC, &unk_jwp0ATrWM_w},
	{0x8F6752362F9226BA, &unk_j2dSNi_SJro},
	{0x8FA6264BF3F6CC00, &unk_j6YmS_P2zAA},
	{0x8FAA16CF2B836A5E, &unk_j6oWzyuDal4},
	{0x911DDE776A40BD5F, &unk_kR3ed2pAvV8},
	{0x91CFCEF572854481, &unk_kc_O9XKFRIE},
	{0x91DADD63F04424CC, &unk_kdrdY_BEJMw},
	{0x9292E87C2C0971E4, &unk_kpLofCwJceQ},
	{0x9348596C2B17F662, &unk_k0hZbCsX9mI},
	{0x9430965913ACAC48, &unk_lDCWWROsrEg},
	{0x9507E9B321A5E0D7, &unk_lQfpsyGl4Nc},
	{0x9545F21464855CAA, &unk_lUXyFGSFXKo},
	{0x969EEFCF02125CC8, &unk_lp7vzwISXMg},
	{0x977746EE1E1394B8, &unk_l3dG7h4TlLg},
	{0x982A9F2DF2165AEA, &unk_mCqfLfIWWuo},
	{0x9871361E4F4A8BCD, &unk_mHE2Hk9Ki80},
	{0x98CA95E231980731, &unk_mMqV4jGYBzE},
	{0x994727DF925602F2, &unk_mUcn35JWAvI},
	{0x9ADD817BAAAC9ECC, &unk_mt2Be6qsnsw},
	{0x9B78C4B4600FF631, &unk_m3jEtGAP9jE},
	{0x9B826253C9363F22, &unk_m4JiU8k2PyI},
	{0x9E6CEF7064891F84, &unk_nmzvcGSJH4Q},
	{0x9E8266E76B8B374D, &unk_noJm52uLN00},
	{0x9EE3E5E2E55760C3, &unk_nuPl4uVXYMM},
	{0x9F1A5BA32BC919FE, &unk_nxpboyvJGf4},
	{0xA03310F7A09280A1, &unk_oDMQ96CSgKE},
	{0xA060128FA423ABB3, &unk_oGASj6Qjq7M},
	{0xA31D887BDF253C04, &unk_ox2Ie98lPAQ},
	{0xA356B323C4C68DB7, &unk_o1azI8TGjbc},
	{0xA49AAB61CEEFF58E, &unk_pJqrYc7v9Y4},
	{0xA6DF04F4962A666E, &unk_pt8E9JYqZm4},
	{0xA7BC2C792E9522C5, &unk_p7wseS6VIsU},
	{0xA8194CCC96CC6BB7, &unk_qBlMzJbMa7c},
	{0xAA8E661F8F609C30, &unk_qo5mH49gnDA},
	{0xABBA0F809548CB02, &unk_q7oPgJVIywI},
	{0xAD3E0D5B2B325FE8, &unk_rT4NWysyX_g},
	{0xADBB0964FB048CDF, &unk_rbsJZPsEjN8},
	{0xAE0B5BA53CF1D110, &unk_rgtbpTzx0RA},
	{0xB14A27A4CEDE020F, &unk_sUonpM7eAg8},
	{0xB1C081BDF5C67913, &unk_scCBvfXGeRM},
	{0xB4E27F586143B7F6, &unk_tOJ_WGFDt_Y},
	{0xB5AF25012031AE8E, &unk_ta8lASAxro4},
	{0xB695D5352170251B, &unk_tpXVNSFwJRs},
	{0xB797198733847833, &unk_t5cZhzOEeDM},
	{0xB7E4FC506F236ADB, &unk_t_T8UG8jats},
	{0xBA14895D53184167, &unk_uhSJXVMYQWc},
	{0xBA41BE0F44157EE4, &unk_ukG_D0QVfuQ},
	{0xBA53EE5A4EDB6025, &unk_ulPuWk7bYCU},
	{0xBAA1DEC848D99690, &unk_uqHeyEjZlpA},
	{0xBB12E6275E353E60, &unk_uxLmJ141PmA},
	{0xBB8CCCD6C9480EB2, &unk_u4zM1slIDrI},
	{0xBDFFA561E397748F, &unk_vf_lYeOXdI8},
	{0xBEC25DAAE8B8B81F, &unk_vsJdqui4uB8},
	{0xBFEE936391AB0C70, &unk_v_6TY5GrDHA},
	{0xC0DD2DBE2EA66F7A, &unk_wN0tvi6mb3o},
	{0xC17A66EF931C359A, &unk_wXpm75McNZo},
	{0xC1F858BF5B86C2A1, &unk_wfhYv1uGwqE},
	{0xC240618E6FC39206, &unk_wkBhjm_DkgY},
	{0xC338A34450310E79, &unk_wzijRFAxDnk},
	{0xC5033DE1122B7917, &unk_xQM94RIreRc},
	{0xC9672DA3B137F7E9, &unk_yWcto7E39_k},
	{0xC9AFACF331B15504, &unk_ya_s8zGxVQQ},
	{0xCB67035ED668CF6B, &unk_y2cDXtZoz2s},
	{0xCC0BEA7EB4767FB7, &unk_zAvqfrR2f7c},
	{0xCC7C51834014666F, &unk_zHxRg0AUZm8},
	{0xCE1D8AB1066500DE, &unk_zh2KsQZlAN4},
	{0xD127CFFB5FBB681E, &unk_0SfP_1_7aB4},
	{0xD1C9F673F6E4F300, &unk_0cn2c_bk8wA},
	{0xD2A8D833D6E9E6FB, &unk_0qjYM9bp5vs},
	{0xD464507F0F9B85C1, &unk_1GRQfw_bhcE},
	{0xD47D3BFCCF1F19E7, &unk_1H07_M8fGec},
	{0xD577BE5D9D68236F, &unk_1Xe_XZ1oI28},
	{0xD70327DD7F7858C1, &unk_1wMn3X94WME},
	{0xDA1895D2FDBB91C6, &unk_2hiV0v27kcY},
	{0xDA5BCE0114C5E71D, &unk_2lvOARTF5x0},
	{0xDA8E15DD00AF9DF8, &unk_2o4V3QCvnfg},
	{0xDD36F1232D151225, &unk_3TbxIy0VEiU},
	{0xDE6477409173AE0E, &unk_3mR3QJFzrg4},
	{0xDEB96ACBA5F1AE62, &unk_3rlqy6XxrmI},
	{0xDEC53D7165C137DF, &unk_3sU9cWXBN98},
	{0xDFDEEE26F2EB96B3, &unk_397uJvLrlrM},
	{0xE2056A6F01642866, &unk_4gVqbwFkKGY},
	{0xE370745671743FB1, &unk_43B0VnF0P7E},
	{0xE3707495ABA4B0B6, &unk_43B0lauksLY},
	{0xE4F67EFC91C84F87, &unk_5PZ__JHIT4c},
	{0xE6F041A2660F83EB, &unk_5vBBomYPg_s},
	{0xE8CB89FEF9C393A0, &unk_6MuJ_vnDk6A},
	{0xE934D19BC291A9BC, &unk_6TTRm8KRqbw},
	{0xE964E0A4AA94C51A, &unk_6WTgpKqUxRo},
	{0xE979BA413BD84D38, &unk_6Xm6QTvYTTg},
	{0xE9BBEA9C12083626, &unk_6bvqnBIINiY},
	{0xEC8DA5652D034630, &unk_7I2lZS0DRjA},
	{0xECE888D4E6D3D505, &unk_7OiI1ObT1QU},
	{0xEDDDF2D305DB7866, &unk_7d3y0wXbeGY},
	{0xF3595D8EFFF26EC0, &unk_81ldjv_ybsA},
	{0xF3DF5271142F155D, &unk_899ScRQvFV0},
	{0xF68E229C52BFA167, &unk_9o4inFK_oWc},
	{0xF886A00DA8C1E804, &unk__IagDajB6AQ},
	{0xF91B5B25CC9B30D9, &unk__RtbJcybMNk},
	{0xF9F03FB6936F64D8, &unk__fA_tpNvZNg},
	{0xFA1009745E07AE07, &unk__hAJdF4Hrgc},
	{0xFB72564D53F83547, &unk__3JWTVP4NUc},
	{0xFC183379B48C6956, &unk__BgzebSMaVY},
	{0xFCEAC354CA8B206E, &unk__OrDVMqLIG4},
	{0xFD618F49CA433160, &unk__WGPScpDMWA},
	{0xFE55AD31F07272B8, &unk__lWtMfBycrg},
	{0xFF966E4351E564D6, &unk__5ZuQ1HlZNY},
	{0xDABB059A519695E4, &sceNpCheckNpAvailability0},
	{0x1A1CFD8960D4B42E, &sceNpGetAccountCountry0},
	{0xF150537917F56702, &sceNpGetAccountDateOfBirth0},
	{0x6BC47DFFBE6EE223, &sceNpGetAccountId0},
	{0x299D4C8FDC841987, &sceNpGetAccountLanguage0},
	{0x20F6F585DD700067, &sceNpGetGamePresenceStatus0},
	{0x8A5C0B338CCE9AEE, &sceNpGetParentalControlInfo0},
	{0x17A138C9CABD0DB8, &sceNpGetUserIdByOnlineId0},
	{0x561D5B8541BA992B, &sceNpInGameMessagePrepare0},
	{0x38DED27F95C43262, &sceNpInGameMessageSendData0},
	{0xB8526968A341023E, &sceNpRegisterGamePresenceCallback0},
	{0x55F45298F9A3F10F, &sceNpRegisterStateCallback0},
	{0x28EFB5D5C802ECDD, &sceNpSetGamePresenceOnline0},
	{0x9A38D35E1F8D1D66, &sceNpUnregisterStateCallback0},
	{0xEF4378573542A508, &unk_70N4VzVCpQg},
	{0x2442C77F8C4FB9FA, &sceNpCheckCallbackForLib0},
	{0x608BEAAAF2728C47, &unk_YIvqqvJyjEc},
	{0xD1CEC76D744A52DE, &unk_0c7HbXRKUt4},
	{0x61BBBA03157A4B4A, &unk_Ybu6AxV6S0o0},
};

MODULE_INIT(libSceNpManager);