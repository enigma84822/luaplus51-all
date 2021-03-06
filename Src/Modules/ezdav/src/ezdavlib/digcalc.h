#ifndef __DIGCALC_H__
#define __DIGCALC_H__
#define HASHLEN 16
typedef char HASH[HASHLEN];
#define HASHHEXLEN 32
typedef char HASHHEX[HASHHEXLEN+1];

/* calculate H(A1) as per HTTP Digest spec */
void DigestCalcHA1(
    const char * pszAlg,
    const char * pszUserName,
    const char * pszRealm,
    const char * pszPassword,
    const char * pszNonce,
    const char * pszCNonce,
    HASHHEX SessionKey
    );

/* calculate request-digest/response-digest as per HTTP Digest spec */
void DigestCalcResponse(
    const HASHHEX HA1,           /* H(A1) */
    const char * pszNonce,       /* nonce from server */
    const char * pszNonceCount,  /* 8 hex digits */
    const char * pszCNonce,      /* client nonce */
    const char * pszQop,         /* qop-value: "", "auth", "auth-int" */
    const char * pszMethod,      /* method from the request */
    const char * pszDigestUri,   /* requested URL */
    const HASHHEX HEntity,       /* H(entity body) if qop="auth-int" */
    HASHHEX Response			/* request-digest or response-digest */
    );

#endif