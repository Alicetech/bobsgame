######################################################################
# Automatically generated by qmake (2.01a) ? 28. ????? 13:01:43 2011
######################################################################

 
# Directories
QT      +=  webkit network





HEADERS =   AuthenticationDialogContainer.h \
 	    WebBroswerDeleget.h \
	    FBApi.h \	    
	    HttpClient.h \
	    UT.h  \
  	    Constants.h \
  	    FBFqlBuilder.h \
 	    QCookieJar.h \
	    ConfigSettings.h \
	    UserObject.h \
	    GraphApiManager.h \
	    SettingsDialog.h \
	    Group.h \
 	    UTThread.h \
 	    lib_json/json_batchallocator.h  \
	    lib_json/json_internalarray.inl \
	    lib_json/json_internalmap.inl \
	    lib_json/json_valueiterator.inl
	    
	    
SOURCES =   main.cpp \
 	    AuthenticationDialogContainer.cpp \
	    WebBroswerDeleget.cpp \
	    FBApi.cpp \	    
	    HttpClient.cpp \
 	    UT.cpp \
 	    FBFqlBuilder.cpp \
 	    QCookieJar.cpp \
	    ConfigSettings.cpp \
	    UserObject.cpp \
	    GraphApiManager.cpp \
	    SettingsDialog.cpp \
	    Group.cpp \
	    lib_json/json_reader.cpp \
	    lib_json/json_value.cpp \
	    lib_json/json_writer.cpp

 




INCLUDEPATH += . lib_json/include lib_json/include/json 
RESOURCES   += resources.qrc
FORMS  = settings.ui authenticationdialog.ui
	     