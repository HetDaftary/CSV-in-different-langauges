delimiter_to_read = ","
delimiter_to_write = ", "

with open('../csv_files/Sample100.csv') as csv_file:
    data = [x.strip().split(",") for x in csv_file.readlines()]
    with open('../Results/Python/without_module/1.csv', 'w') as csv_write_file:
        csv_write_file.write('\n'.join([', '.join(x) for x in data]))

with open('../csv_files/Sample500.csv') as csv_file:
    data = [x.strip().split(",") for x in csv_file.readlines()]
    with open('../Results/Python/without_module/2.csv', 'w') as csv_write_file:
        csv_write_file.write('\n'.join([', '.join(x) for x in data]))