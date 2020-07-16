#include<stdio.h>
#include<malloc.h>
#pragma warning (disable:4996)
int main() {
	FILE *input, *output;

	input = fopen("block.inp", "rt");
	output = fopen("block.out", "wt");

	int T, n;

	fscanf(input, "%d", &T);
	for (int x = 0; x < T; x++) {
		fscanf(input, "%d", &n);
		int **b;
		b = (int **)malloc(sizeof(int*)*n);
		for (int i = 0; i < n; i++) {
			b[i] = (int*)malloc(sizeof(int)*(i+1));
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				fscanf(input, "%d", &b[i][j]);
			}
		}
		
		
		
		for (int i = n - 1; i > -1; i--) {
			for (int j = 0; j < i + 1; j++) {
				if (b[i][j] == -1) {
					if (j == 0) {
						if (i != 0) {
							if (b[i - 1][j] != -1 && b[i][j + 1] != -1) {
								b[i][j] = ((b[i - 1][j] + 100) - (b[i][j + 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
					else if (j == i) {
						if (i != 0) {
							if (b[i - 1][j - 1] != -1 && b[i][j - 1] != -1) {
								b[i][j] = ((b[i - 1][j - 1] + 100) - (b[i][j - 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
						
					}
					else if (j != 0) {
						if (i != 0) {
							if (b[i - 1][j] != -1 && b[i][j + 1] != -1) {
								b[i][j] = ((b[i - 1][j] + 100) - (b[i][j + 1] % 100)) % 100;
							}
							else if (b[i - 1][j - 1] != -1 && b[i][j - 1] != -1) {
								b[i][j] = ((b[i - 1][j - 1] + 100) - (b[i][j - 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
				}
			}
		}
		for (int i = n - 1; i > -1; i--) {
			for (int j = i; j > -1 + 1; j--) {
				if (b[i][j] == -1) {
					if (j == i) {
						if (i != 0) {
							if (b[i - 1][j - 1] != -1 && b[i][j - 1] != -1) {
								b[i][j] = ((b[i - 1][j - 1] + 100) - (b[i][j - 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
					else if (j == 0) {
						if (i != 0) {
							if (b[i - 1][j] != -1 && b[i][j + 1] != -1) {
								b[i][j] = ((b[i - 1][j] + 100) - (b[i][j + 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
					else if (j != 0) {
						if (i != 0) {
							if (b[i - 1][j] != -1 && b[i][j + 1] != -1) {
								b[i][j] = ((b[i - 1][j] + 100) - (b[i][j + 1] % 100)) % 100;
							}
							else if (b[i - 1][j - 1] != -1 && b[i][j - 1] != -1) {
								b[i][j] = ((b[i - 1][j - 1] + 100) - (b[i][j - 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
				}
			}
		}
		for (int a = n; a > 0; a--) {
			for (int i = n - 1; i > n - (a + 1); i--) {
				for (int j = n - 1; i - j < n - a + 1; j--) {
					if (i - j > n - a - 1 && i >= j) {
						if (b[i][j] == -1) {
							if (j == i) {
								if (i != 0) {
									if (b[i - 1][j - 1] != -1 && b[i][j - 1] != -1) {
										b[i][j] = ((b[i - 1][j - 1] + 100) - (b[i][j - 1] % 100)) % 100;
									}
									else if (i != n - 1) {
										if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
											b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
										}
									}
								}
							}
							else if (j == 0) {
								if (i != 0) {
									if (b[i - 1][j] != -1 && b[i][j + 1] != -1) {
										b[i][j] = ((b[i - 1][j] + 100) - (b[i][j + 1] % 100)) % 100;
									}
									else if (i != n - 1) {
										if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
											b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
										}
									}
								}
							}
							else if (j != 0) {
								if (i != 0) {
									if (b[i - 1][j] != -1 && b[i][j + 1] != -1) {
										b[i][j] = ((b[i - 1][j] + 100) - (b[i][j + 1] % 100)) % 100;
									}
									else if (b[i - 1][j - 1] != -1 && b[i][j - 1] != -1) {
										b[i][j] = ((b[i - 1][j - 1] + 100) - (b[i][j - 1] % 100)) % 100;
									}
									else if (i != n - 1) {
										if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
											b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
										}
									}
								}
							}
						}
					}
						//fprintf(output, "%d%d ", i, j);
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i - j > -1; i--) {
				if (b[i][j] == -1) {
					if (i == j) {
						if (i != 0) {
							if (b[i - 1][j - 1] != -1 && b[i][j - 1] != -1) {
								b[i][j] = ((b[i - 1][j - 1] + 100) - (b[i][j - 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
					else if (j == 0) {
						if (i != 0) {
							if (b[i - 1][j] != -1 && b[i][j + 1] != -1) {
								b[i][j] = ((b[i - 1][j] + 100) - (b[i][j + 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
					else if (j != 0) {
						if (i != 0) {
							if (b[i - 1][j] != -1 && b[i][j + 1] != -1) {
								b[i][j] = ((b[i - 1][j] + 100) - (b[i][j + 1] % 100)) % 100;
							}
							else if (b[i - 1][j - 1] != -1 && b[i][j - 1] != -1) {
								b[i][j] = ((b[i - 1][j - 1] + 100) - (b[i][j - 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
				}
			}
		}
		/*for (int i = 0; i < n; i++) {
			for (int j = i; j < i + 1; j++) {
				if (b[i][j] == -1) {
					if (j == i) {
						if (i != 0) {
							if (b[i - 1][j - 1] != -1 && b[i][j - 1] != -1) {
								b[i][j] = ((b[i - 1][j - 1] + 100) - (b[i][j - 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
					else if (j == 0) {
						if (i != 0) {
							if (b[i - 1][j] != -1 && b[i][j + 1] != -1) {
								b[i][j] = ((b[i - 1][j] + 100) - (b[i][j + 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
					else if (j != 0) {
						if (i != 0) {
							if (b[i - 1][j] != -1 && b[i][j + 1] != -1) {
								b[i][j] = ((b[i - 1][j] + 100) - (b[i][j + 1] % 100)) % 100;
							}
							else if (b[i - 1][j - 1] != -1 && b[i][j - 1] != -1) {
								b[i][j] = ((b[i - 1][j - 1] + 100) - (b[i][j - 1] % 100)) % 100;
							}
							else if (i != n - 1) {
								if (b[i + 1][j] != -1 && b[i + 1][j + 1] != -1) {
									b[i][j] = (b[i + 1][j] + b[i + 1][j + 1]) % 100;
								}
							}
						}
					}
				}
			}
		}*/
		if (b[0][0] == -1) {
			if (b[1][0] != -1 && b[1][1] != -1) {
				b[0][0] = (b[1][0] + b[1][1]) % 100;
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				fprintf(output, "%d ", b[i][j]);
			}
			fprintf(output, "\n");
		}
		
		for (int i = 0; i < n; i++) {
			free(b[i]);
		}
		free(b);
	}
	
	fclose(input);
	fclose(output);
}