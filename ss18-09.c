#include <stdio.h>
#include <string.h>

int main(){
	struct Dish{
	int id;
	char name;
	char price;
};
	struct Dish menu[100] = {
		{1, "Nem", 10},
		{2, "Pho", 30},
		{3, "Bun rieu", 35},
		{4, "Banh gio", 20},
		{5, "Banh chung", 15},
	};
	int choice;
	int n = 5;
	do{
		printf("\nMENU\n");
		printf("1. In ra gia tri cac phan tu co trong menu mon an\n");
		printf("2. Them mot phan tu vao vi tri chi dinh\n");
		printf("3. Sua mot phan tu vao vi tri chi dinh\n");
		printf("4. Xoa mot phan tu o vi tri chi dinh\n");
		printf("5. Sap xep cac phan tu\n");
		printf("6. Tim kiem phan tu theo name nhap vao\n");
		printf("7. Thoat\n");
		printf("Lua chon cua ban la: ");
		scanf("%d", &choice);
		fflush(stdin);
		switch (choice){
			case 1:
				for (int i = 0; i < n; i++) {
					printf("%d, %s, %.2f\n", menu[i].id, menu[i].name, menu[i].price);
				}
				break;
			case 2:
				int position;
				struct Dish newDish;
				printf("Nhap id: ");
			    scanf("%d", &newDish.id);
			    fflush(stdin);
			    printf("Nhap mon muon them: ");
			    fgets(newDish.name, sizeof(newDish.name), stdin);
			    newDish.name[strcspn(newDish.name), "\n"] = '\0';
			    printf("Nhap gia tien: ");
			    scanf("f", &newDish.price);
			    printf("Nhap vi tri muon them: ");
			    scanf("%d", &position);
			    if (position < 0 || position > n || position >= 100){
			    	printf("Vi tri them vao khong hop le\n");
			    	return 1;
				}
				for (i = n; i > position; i--){
					menu[i] = menu[i - 1];
				}
				menu[position] = newDish;
				n++;
				break;
			case 3:
				int food;
				struct Dish check;
				printf("Nhap vi tri can sua: ");
				scanf("%d", &food);
				printf("Nhap ten mon thay doi: ");
				fgets(check.name, sizeof(check.name), stdin);
				check.name[strcspn(check.name, "\n")] = '\0';
				printf("Nhap gia mon muon doi: ");
				scanf("%f", &check.price);
				menu[food] = check;
				break;
			case 4:
				int position;
				printf("Nhap vi tri mon can xoa: ");
			    scanf("%d",&position);
			    if(position<0||position>=size){
				printf("Vi tri xoa mon khong hop le!\n");
				return 1;
				}	
			    for(i=position;i<size-1;i++){
			    	menu[i] = menu[i + 1];
				}
				size--;
				break;
			case 5:
				int i, j;
				for (int i = 0; i < n - 1; i++) {
					for (int j = i + 1; j < n; j++) {
						if (menu[i].price > menu[j].price) {
							struct Dish temp = menu[i];
							menu[i] = menu[j];
							menu[j] = temp;
						}
					}
				}
				break;
			case 6:
				char findDish[50];
				int found = 0;
				fflush(stdin);
				printf("Nhap ten mon can tim: ");
				fgets(findDish, sizeof(findDish), stdin);
				findDish[strcspn(findDish, "\n")] = '\0';
				for (int i = 0, i < n; i++){
					if (strcmp(menu[i].name, findDish) == 0){
						printf("Mon an can tim o vi tri %d\n", i + 1);
						printf("%d. %s: %.2f\n", menu[i].id, menu[i].name, menu[i]. price);
						found = -1
					}
				}
				if (!found) {
					printf("Khong tim thay mon trong menu\n");
				}
				break;
			case 7:
				printf("Thoat\n");
				break;
			default:
				printf("Lua chon khong hop le. Hay chon lai\n");
				break;
		}
	} while (choice != 7);
		return 0;
} 

