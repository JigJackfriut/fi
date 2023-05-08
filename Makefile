# MakeFile for restChat
# server using C++ Microservice
# sudo mkdir /var/www/html/fi
# sudo chown ubuntu /var/www/html/fi

all: PutHTML fi

PutHTML:
	cp restChat.html /var/www/html/fi/
	cp restChat.css /var/www/html/fi/
	cp restChat.js /var/www/html/fi/
	
	echo "Current contents of your HTML directory: "
	ls -l /var/www/html/fi/

fi : fi.cpp httplib.h
	$(CXX) -o fi $(CXXFLAGS) fi.cpp $(OPENSSL_SUPPORT) $(ZLIB_SUPPORT) $(BROTLI_SUPPORT) 

clean:
	rm fi *.o
