if [ "$1" = "on" ]; then
	sed -i 20's/\boff/on/' /etc/nginx/sites-available/nginx.conf && \
	nginx -s reload
elif [ "$1" = "off" ]; then
	sed -i 20's/\bon/off/' /etc/nginx/sites-available/nginx.conf && \
	nginx -s reload
fi
