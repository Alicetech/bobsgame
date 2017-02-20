
#ifndef DEF_QCOOKIEJAR
#define DEF_QCOOKIEJAR

#include <QtNetwork>

class QCookieJar : public QNetworkCookieJar
{
	Q_OBJECT
public:
	QCookieJar (QString path, QObject *parent = 0);  //constructeur, impl�mentera le chargement des cookies
	~QCookieJar ();  //destructeur, impl�mente la sauvegarde des cookies
	QList<QNetworkCookie> cookiesForUrl ( const QUrl & url ) const; //on ne touche pas
	bool setCookiesFromUrl ( const QList<QNetworkCookie> & cookieList, const QUrl & url ); //on ne touche pas

private:
	QString file; //pour retenir o� l'on doit sauvagarder les cookies
};

#endif

