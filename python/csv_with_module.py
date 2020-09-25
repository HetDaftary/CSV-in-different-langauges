import csv

with open('../csv_files/Sample100.csv') as csv_file:
    reader = csv.reader(csv_file, delimiter = ",")
    with open('../Results/Python/with_module/1.csv', 'w') as csv_write_file:
        writer = csv.writer(csv_write_file)
        writer.writerows(reader)

with open('../csv_files/Sample500.csv') as csv_file:
    reader = csv.reader(csv_file, delimiter = ",")
    with open('../Results/Python/with_module/2.csv', 'w') as csv_write_file:
        writer = csv.writer(csv_write_file)
        writer.writerows(reader)