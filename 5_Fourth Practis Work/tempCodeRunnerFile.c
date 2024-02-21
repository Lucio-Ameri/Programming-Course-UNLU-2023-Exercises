void Show_Register(class classroom, int index, int quantity_of_students, int quantity_of_notes) {
    int j;

    printf("EL PROFESOR A CARGO DE ESTA CLASE ES: %s\n", classroom.teacher);

    printf("%-15s | %-15s | %-15s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s\n", "NAME", "SURNAME", "BIRTHDAY", "NOTE 1", "NOTE 2", "NOTE3", "NOTE 4", "NOTE 5", "NOTE 6", "NOTE 7", "NOTE 8", "NOTE 9", "NOTE 10");
    
    for (j = 0; j < quantity_of_students; j++) {
        printf("%-15s | %-15s | %-02d-%02d-%04d | ", classroom.students[j].name, classroom.students[j].surname, classroom.students[j].date_of_birthday.day, classroom.students[j].date_of_birthday.month, classroom.students[j].date_of_birthday.year);

        for (int k = 0; k < quantity_of_notes; k++) {
            printf("%-10.2f | ", classroom.students[j].note[k]);
        }
        printf("\n");
    }
    printf("\n");
    system("Pause");
    system("cls");
}
