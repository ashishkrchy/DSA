class Node{
    public: 
        string token;
        int time;
        Node* next;

        Node(string tokenId, int data){
            token = tokenId;
            time = data;
            next = nullptr;
        }
};


class AuthenticationManager {
public:
    int expiresIn;
    Node* head;
    Node* tail;

    AuthenticationManager(int timeToLive) {
        expiresIn = timeToLive;
        head = tail = nullptr;
    }

    void generate(string tokenId, int currentTime) {
        Node* newNode = new Node(tokenId, currentTime);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void renew(string tokenId, int currentTime) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr && curr->token != tokenId) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) return;

        if (curr->time + expiresIn <= currentTime) return;

        if (prev) prev->next = curr->next;
        else head = curr->next;

        if (curr == tail) tail = prev;

        delete curr;

        Node* newNode = new Node(tokenId, currentTime);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int countUnexpiredTokens(int currentTime) {

        while (head && head->time + expiresIn <= currentTime) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        if (!head) tail = nullptr;

        int count = 0;
        Node* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }

        return count;
    }
};


/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */