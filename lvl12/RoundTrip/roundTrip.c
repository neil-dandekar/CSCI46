#include <stdio.h>
#include <libsocket/libinetsocket.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

// Returns the current time (since Jan 1, 1970) in seconds
double getTime() {
    struct timeval now;
        gettimeofday(&now, NULL);
        return now.tv_sec + now.tv_usec / 1000000.0;
}

// Open connection to server, return FILE * and fd
void openConnection(char* name, char* port, FILE **s, int *fd) {

    char* host = strcat(name, ".cs.sierracollege.edu");

    // Open connection to name.cs.sierracollege.edu
    *fd = create_inet_stream_socket(host, port, LIBSOCKET_IPv4, 0);

    // Confirm connection
    if (*fd < 0) {
        printf("Can't make connection.\n");
        exit(1);
    }
    else printf("Connected to %s.\n", host);

    // Convert file descriptor to FILE *
    *s = fdopen(*fd, "r+");
}

// Send response to server
void sendData(FILE **s, char* data) {
    fputs(data, *s);
}

// Get response from server
char* getResponse(FILE **s) {
    char *line = malloc(100 * sizeof(char));
    fgets(line, 100, *s);
    return line;
}

// Close connection to server
void closeConnection(FILE *s, int fd) {
    fclose(s);
    close(fd);
}

// Returns RoundTrip time
double getRoundTrip(char* host) {
    FILE *s = NULL;
    int fd;
    openConnection(host, "5055", &s, &fd);

    // Get Time
    double initial = getTime();

    // Send Data
    sendData(&s, "Hello\n");
    printf("Sent \"Hello\"\n");
    
    // Receive Data and Trim Newline
    char* response = getResponse(&s);
    char *nl = strchr(response, '\n');
    if (nl) *nl = '\0';

    // Get Time
    double final = getTime();

    // Display Response
    printf("Received \"%s\"\n", response);
    
    closeConnection(s, fd);

    // Calculate and return Roundtrip time
    return (final - initial) * 1000;

}

int main(int argc, char *argv[]) {
    char* host = argv[1];
    double avgTime = 0;
    double roundTrip;
    int numTrials = 3;

    FILE *s = NULL;
    int fd;
    openConnection(host, "5055", &s, &fd);
    printf("\n");

    for (int i = 1; i <= numTrials; i++) {
        // Get Time
        double initial = getTime();

        // Send Data
        sendData(&s, "Hello\n");
        printf("%d: Sent \"Hello\"\n", i);
        
        // Receive Data and Trim Newline
        char* response = getResponse(&s);
        char *nl = strchr(response, '\n');
        if (nl) *nl = '\0';

        // Get Time
        double final = getTime();

        // Display Response
        printf("%d: Received \"%s\"\n", i, response);
        
        // Calculate and return Roundtrip time
        roundTrip = (final - initial) * 1000;
        avgTime += roundTrip;
        printf("Roundtrip: %.2f ms\n\n", roundTrip);
    }
    closeConnection(s, fd);
    printf("Average Roundtrip: %.2f ms\n", avgTime/numTrials);
}