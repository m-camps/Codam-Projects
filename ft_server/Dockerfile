# SELECT OS
FROM 	debian:buster

# EXPOSE PORTS
EXPOSE 80 443

# COPY ALL FILES TO DOCKER ROOT
COPY 	srcs/. /root/

# GET UPDATES
RUN 	apt-get update && \
		apt-get install -y apt-utils nginx openssl wget mariadb-server php-fpm php-gd php-mbstring php-mysql

# CONFIGURE SSL
RUN 	openssl req -newkey rsa:2048 -nodes -x509 -days 365 \
        -subj '/C=NL/L=DENHAAG/O=Codam/OU=Student/CN=Max' \
        -keyout /etc/nginx/localhost-key.pem -out /etc/nginx/localhost.pem

# CONFIGURE NGINX
RUN 	mv /root/nginx.conf /etc/nginx/sites-available && \
		mv /root/index.sh . && \
		ln -fs /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled && \
		nginx -t && \
		rm -rf /etc/nginx/sites-enabled/default

# CONFIGURE MYSQL DATABASE
RUN		service mysql start && \
		echo "create user 'Max'@'localhost' identified by 'password';" | mysql -u root && \
		echo "create database wordpress;" | mysql -u root && \
		echo "grant all privileges on *.* to 'Max'@'localhost';" | mysql -u root && \
		echo "flush privileges;" | mysql -u root

# CONFIGURE WORDPRESS
RUN		wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \	
		chmod +x wp-cli.phar && \
		mv wp-cli.phar /usr/local/bin/wp && \
		wp core download --allow-root --path=var/www/html/wordpress && \
		mv /root/wp-config.php /var/www/html/wordpress && \
		service mysql restart && \
		wp core install --allow-root --url=localhost --path=/var/www/html/wordpress --title=Wordpress --admin_user=max \
		--admin_password=password --admin_email=max@student.codam.nl --skip-email

# CONFIGURE PHPMYADMIN
RUN		mkdir /var/www/html/wordpress/phpmyadmin && \
		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz && \
		tar xzfv phpMyAdmin-5.0.1-english.tar.gz -C /root && \
		cp -a /root/phpMyAdmin-5.0.1-english/. /var/www/html/wordpress/phpmyadmin && \
		rm -rf root/phpMyAdmin-5.0.1-english && \
		rm -rf phpMyAdmin-5.0.1-english.tar.gz && \
		mv /root/config.inc.php /var/www/html/wordpress/phpmyadmin

# GRANT PERMISSIONS
RUN 	chown -R www-data:www-data /var/www/* && \
		chmod -R 755 /var/www/*

# INCREASE UPLOAD SIZE
RUN		sed -i '/upload_max_filesize/c upload_max_filesize = 20M' /etc/php/7.3/fpm/php.ini
RUN		sed -i '/post_max_size/c post_max_size = 20M' /etc/php/7.3/fpm/php.ini

# START SERVICES
CMD 	service mysql restart && \
		service php7.3-fpm start && \
		nginx -g 'daemon off;'