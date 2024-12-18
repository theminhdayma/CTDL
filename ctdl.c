#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Dinh nghia 1 node
typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

// Tao node moi
Node* createNode(int value) {
	// Cap nhat bo nho 
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

// Them 1 phan tu vao dau list
void insertHead(Node** head, int value) {
	Node* newNode = createNode(value);
	newNode->next = *head;
	if(*head != NULL) {
		(*head)->prev = newNode;
	}
	*head= newNode;
    printf("Da them thanh cong %d vao dau danh sach", value);
}

// Them 1 phan tu o cuoi danh sanh
void insertEnd(Node** head, int value) {
	// Tao Node
	Node* newNode = createNode(value);
	
	if(*head == NULL) {
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
    printf("Da them thanh cong %d vao cuoi danh sach", value);
}

// Chen vao vi tri bat ky 
void insertElement(Node** head, int value, int position) {
    Node* newNode = createNode(value);

    // Neu chen vao vi tri dau
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    Node* temp = *head;

    // Duyet danh sach de tim vi tri
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // Neu vi tri khong ton tai
    if (temp == NULL) {
        printf("Vi tri khong ton tai\n");
        free(newNode);
        return;
    }

    // Chen vao vi tri bat ky
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Da them thanh cong %d vao vi tri thu %d danh sach", value, position);
}


// Xoa phan tu dau danh sach
void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("xoa phan tu dau thanh cong.\n");
}

// Xoa phan tu cuoi danh sach
void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("Danh sanh rong.\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        printf("Xoa phan tu cuoi thanh cong.\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("Xoa phan tu cuoi thanh cong.\n");
}

// Xoa phan tu theo gia tri
void deleteByValue(Node** head, int value) {
    if (*head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    Node* temp = *head;

    // Duyet qua danh sach de tim gia tri
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    // Neu khong tim thay gia tri
    if (temp == NULL) {
        printf("Khong tim thay gia tri trong danh sach.\n");
        return;
    }

    // Neu phan tu can xoa la dau danh sach
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Xoa phan tu co gia tri %d thanh cong.\n", value);
        return;
    }

    // Neu phan tu can xoa la cuoi danh sach
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
        printf("Xoa phan tu co gia tri %d thanh cong.\n", value);
        return;
    }

    // Neu phan tu can xoa nam giua danh sach
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    printf("Xoa phan tu co gia tri %d thanh cong.\n", value);
}


// Duyet danh sach theo next
void printList(Node *head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
	Node* temp = head;
	while(temp != NULL) {
		printf("%d <-> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// Duyet danh sach theo prev
void printListReverse(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
	
	Node* head = NULL;
	int choice;
	
	do {
		printf("\n\n\n===========================MENU================================\n");
		printf("1. Them 1 phan tu vao dau\n");
		printf("2. Them 1 phan tu vao cuoi\n");
		printf("3. Chen phan tu vao vi tri bat ky\n");
		printf("4. Xoa phan tu dau danh sach\n");
		printf("5. Xoa phan tu cuoi danh sach\n");
        printf("6. Xoa phan tu theo gia tri\n");
        printf("7. Xem danh sach (duyet tu dau toi cuoi)\n");
        printf("8. Xem danh sach (duyet tu cuoi len dau)\n");
        printf("9. Thoat\n");
		printf("Moi chon: ");
		
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Moi ban nhap gia tri can them: ");
				int value;
				scanf("%d", &value);
				insertHead(&head, value);
                sleep(2);
                system("cls");
				break;
			case 2:				
				printf("Moi ban nhap gia tri can them: ");
				int value1;
				scanf("%d", &value1);
				insertEnd(&head, value1);
                sleep(2);
                system("cls");
				break;
			case 3: 
				printf("Moi ban nhap vao vi tri can chen: ");
				int pos;
				scanf("%d", &pos);
				printf("Moi ban nhap gia tri phan tu can chen: ");
				int value2;
				scanf("%d", &value2);
				insertElement(&head, value2, pos);
                sleep(2);
                system("cls");
				break;
			case 4:
                deleteHead(&head);
                sleep(2);
                system("cls");
                break;
			case 5:
                deleteEnd(&head);
                sleep(2);
                system("cls");
                break;
            case 6:
                printf("Nhap gia tri phan tu can xoa: ");
                int deleteValue;
                scanf("%d", &deleteValue);
                deleteByValue(&head, deleteValue);
                sleep(2);
                system("cls");
                break;
			case 7:
                printf("Danh sach: ");
				printList(head);
                sleep(2);
                system("cls");
				break;
            case 8:
                printf("Danh sach: ");
                printListReverse(head);
                sleep(2);
                system("cls");
                break;
            case 9: 
                exit(0);
			default: 
				printf("Moi chon lai\n");
		}
	}while(1 == 1);
	
	return 0;
}
