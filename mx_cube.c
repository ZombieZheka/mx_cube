void mx_printchar(char);

void mx_printspaces(int n) {
	for (int i = 0; i < n; i++)
		mx_printchar(' ');
}

void mx_print_plus_line(int n, int str_num) {
	mx_printchar('+');
	for (int i = 0; i < 2 * n; i++) {
		mx_printchar('-');
	}
	mx_printchar('+');
	mx_printspaces((str_num == 1 + n / 2) ? str_num - 1 : 0);
	if (str_num == 1 + n / 2)
		mx_printchar('|');
}

void mx_print_slash_line(int n, int str_num) {
	mx_printchar('/');
	mx_printspaces(2 * n);
	mx_printchar('/');
	mx_printspaces((str_num - 1 < n / 2) ? str_num - 1 : n / 2);
	mx_printchar('|');
}

void mx_print_vertical_slash_line(int n, int str_num) {
	mx_printchar('|');
	mx_printspaces(2 * n);
	mx_printchar('|');
	mx_printspaces((n + n / 2 + 1 - str_num < n / 2) ? n + n / 2 + 1 - str_num : n / 2);
	if (str_num == n + 1) {
		mx_printchar('+');
	}
	else if (str_num > n + 1) {
		mx_printchar('/');
	}
	else {
		mx_printchar('|');
	}
}

void mx_cube(int n) {
	if (n <= 1)
		return;

	for (int str_num = 0; str_num < n + n / 2 + 3; str_num++) {
		mx_printspaces(n / 2 - str_num + 1);

		if (str_num == 0
		|| str_num == 1 + n / 2
		|| str_num == n + n / 2 + 2)
			mx_print_plus_line(n, str_num);
		else if(str_num < 1 + n / 2)
			mx_print_slash_line(n, str_num);
		else
			mx_print_vertical_slash_line(n, str_num);
	mx_printchar('\n');
	}
}

int main(void) {
	mx_cube(1);
	mx_cube(2);
	mx_cube(3);
	mx_cube(4);
}

