pin connection:

data0=>pd14

data1=>pd15

data2=>pd0

data3=>pd1

data4=>pe7

data5=>pe8

data6=>pe9

data7=>pe10

data8=>pe11

data9=>pe12

data10=>pe13

data11=>pe14

data12=>pe15

data13=>pd8

data14=>pd9

data15=>pd10

cs=>pc7 

dc=>pd13  low:cmd,high:data

rd=>pd4

wr=>pd5

rst=>pe3  active low


im0:im1:im2 => 1:0:0 (if configurable)


//////////////////////////////////////

introduction:

Using this driver to test if otm8009a LCD module works.
refresh rate is very low,about 10 secs every frame.
partilly compatible with nt35510.
 
driving otm8009a with stm32h750`s fmc may cause snow screen or rainbow screen,because dataX pins output wrong.
when powered without FPC connected,backlight drive chip will burn out. 

