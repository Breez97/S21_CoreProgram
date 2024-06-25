#include <stdio.h>
#include <fcgi_stdio.h>

int main() {
    while (FCGI_Accept() >= 0) {
        printf("Content-type: text/html\r\n\r\n");
		printf("<html>\n");
		printf("<head><title>Hello World</title></head>\n");
		printf("<body>\n");
		printf("<h1>Hello World!</h1>\n");
		printf("</body>\n");
		printf("</html>\n");
    }
    return 0;
}
