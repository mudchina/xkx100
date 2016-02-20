//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "长坂坡");
	set ("long", @LONG
三国时这里是著名的战场。史载，东汉建安十三年（公元 208年）
刘备被曹操追击至此，与张飞等数十人骑马脱逃，随军眷属被曹军围困
于此，部将赵云单枪匹马，身抱刘备之子阿斗，浴血奋战，力保刘妻甘
夫人突围。北面遥对锦屏山，传为当时曹操登高观阵之处，景色秀丽，
风光宜人。 
LONG);
	set("exits", ([  
		"east" : __DIR__"dangyangqiao",
	]));
	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
