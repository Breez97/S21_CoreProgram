FROM nginx:latest

WORKDIR /home

COPY ./nginx/nginx.conf /etc/nginx
COPY ./server.c .
COPY ./run.sh .

RUN apt-get update && apt-get install \
    gcc \
	spawn-fcgi \
    libfcgi-dev \
	-y

CMD ["sh", "./run.sh"]