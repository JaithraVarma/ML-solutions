import re
with open('tiling.h') as file:
    file_contents = file.readlines()

with open('multi_layer_overlay.h') as file1:
    file_contents1 = file1.readlines()

############################ Predefined #######################
max_mem = 1.5
###############################################################


dim_vals1 = []
flag = 0
for i in file_contents1:
    if 'wts_ddr_offset' in i:
        flag = 1
        continue
    if '};' in i:
        break
    if flag == 1:
        temp = i.split('/')
        dim_vals1.append(int(temp[3]))
        # print(int(temp[3]))


######################################## Checking wts_ddr_dim ##############################################
dim_vals = []
for i in file_contents:
    if 'wts_ddr_dim_' in i:
        temp = i.split(' ')
        val = int(re.split('{|}',temp[3])[1])
        var = temp[1]
        dim_vals.append(int(val))
        # print(var, val)


flag = 0
cnt = 0
for i,j in zip(dim_vals,dim_vals1):
    cnt+=1
    if i!=j:
        flag = 1
        break
if flag == 0:
    print('Checking wts_ddr_dim Success')
else:
    print('Checking wts_ddr_dim Failed')
    print(f'There is a mismatch at wts_ddr_dim_{cnt},',i," is not equal to ",j,'\n')
#####################################################################################################################


######################################## Checking wts_dim with with wts_repetition ##############################################
dim_vals = []
rep_vals = []
for i in file_contents:
    if 'wts_dim_' in i:
        temp = i.split(' ')
        val = int(re.split('{|}',temp[3])[1])
        var = temp[1]
        dim_vals.append(int(val))
    if 'wts_repetition_' in i:
        temp = i.split(' ')
        val = int(re.split(';',temp[3])[0])
        var = temp[1]
        rep_vals.append(int(val))
        # print(var, val)


flag = 0
for i,j,k in zip(dim_vals,rep_vals,dim_vals1):
    if i*j!=k:
        flag = 1
        break
if flag == 0:
    print('Checking wts_dim with with wts_repetition Success')
else:
    print('Checking wts_dim with with wts_repetition Failed')
    print(f'There is a mismatch, wts_dim * wts_repetition != wts_ddr_offset ({i} * {j} != {k}) \n')
#####################################################################################################################

######################################## Checking ifm_dim greater the ifmsv_dim ##############################################
ifm_vals = []
ifmsv_vals = []
for i in file_contents:
    if 'ifm_dim_' in i:
        temp = re.split(' |{|}|,',i)
        size = int(temp[4])*int(temp[6])*int(temp[8])*int(temp[10])
        ifm_vals.append(size)
        # print(size)
    if 'ifmsv_dim_' in i:
        temp = re.split(' |{|}|,',i)
        size = int(temp[4])*int(temp[6])*int(temp[8])*int(temp[10])
        ifmsv_vals.append(size)
        # print(size)



flag = 0
for i,j in zip(ifm_vals,ifmsv_vals):
    if j>i:
        flag = 1
        break
if flag == 0:
    print('Checking ifm_dim greater the ifmsv_dim Success')
else:
    print(f'Checking ifm_dim greater the ifmsv_dim Failed, (ifmsv_dim > ifm_dim i.e {j} > {i})')
#####################################################################################################################


######################################## Checking ifmsv, wtssv, ofmsv contraints for 1.5mb limit ##############################################
ofmsv_vals = []
ifmsv_vals = []
ifm2sv_vals = []
wtssv_vals = []

for i in file_contents:
    if 'ifmsv_dim_' in i:
        temp = re.split(' |{|}|,',i)
        size = int(temp[4])*int(temp[6])*int(temp[8])*int(temp[10])
        ifmsv_vals.append(size)
        ifm2sv_vals.append(0)
        # print('ifm',size)
    if 'ifm2sv_dim_' in i:
        temp = re.split(' |{|}|,',i)
        size = int(temp[4])*int(temp[6])*int(temp[8])*int(temp[10])
        ifm2sv_vals.pop()
        ifm2sv_vals.append(size)
        # print('ifm2',size)
    if 'wtssv_dim_' in i:
        temp = re.split(' |{|}',i)
        size = int(temp[4])
        wtssv_vals.append(size)
        # print('wtssv', temp[4])
    if 'ofmsv_dim_' in i:
        temp = re.split(' |{|}|,',i)
        size = int(temp[4])*int(temp[6])*int(temp[8])*int(temp[10])
        ofmsv_vals.append(size)
        # print('ofm',size)
    

# print(len(ifmsv_vals), len(ifm2sv_vals), len(wtssv_vals), len(ofmsv_vals))
# print(ifmsv_vals)
# print(ifm2sv_vals)
# print(ofmsv_vals)
# print(wtssv_vals)

flag = 0
for i,j,k,l in zip(ifmsv_vals,ifm2sv_vals,ofmsv_vals,wtssv_vals):
    mem = (i+j+k+l)/(1024*1024)
    if mem>max_mem:
        flag = 1
        break
if flag == 0:
    print('Checking ifmsv, wtssv, ofmsv contraints for 1.5mb limit Success')
else:
    print(f'Checking ifmsv, wtssv, ofmsv contraints for 1.5mb limit Failed - {i} + {j} + {k} + {l} / (1024*1024) is greater than 1.5')
#####################################################################################################################