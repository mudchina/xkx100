// Room: /d/yanping/yamen.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "府衙");
	set("long", @LONG
延平府治南平县，设于东汉建安元年，取汉王朝派兵入闽平定南疆
之意。大宋文天祥曾在此设都督府，不屈抗元，留名汗青。开台圣王郑
成功，永历十三年，受南明永历皇帝（桂王）赐封延平郡王。后仕于南
明隆武皇帝，赐“宋”姓，民间习称“国姓爷”。
    这里便是延平府的大衙。堂上两排水火无情棍拱着“肃静”、“回
避”二牌，梁上也是不能免俗的“明镜高悬”四字牌匾。
LONG );
	set("exits", ([
		"south" : __DIR__"road2",
	]));
	set("objects", ([
		"/d/city/npc/yayi" : 2,
	]));
	set("coor/x", 1480);
	set("coor/y", -6180);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
