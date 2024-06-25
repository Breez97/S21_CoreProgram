FROM alpine

WORKDIR /home

RUN apk update && apk add --no-cache \
    nginx \
    build-base \
    spawn-fcgi \
    fcgi \
    fcgi-dev

COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./server.c .
COPY ./run.sh .

RUN gcc server.c -o server -lfcgi && \
    chmod +x run.sh && \
    mkdir -p /var/run/nginx && chown -R nginx:nginx /var/run/nginx

USER nginx

CMD ["sh", "./run.sh"]

HEALTHCHECK --interval=5m --timeout=3s CMD curl -f http://localhost/ || exit 1
