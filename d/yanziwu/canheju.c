//ROOM: /d/yanziwu/canheju.c

inherit ROOM;

void create()
{
	set("short", "参合居");
	set("long",@LONG
这是慕容世家首脑人物日常起居之地，布置得华丽中不乏清雅，平
实中透着高贵。楠木方桌，大太师椅，以及墙上的字画都透着一股非凡
之气。
LONG  );
	set("exits", ([
		"west" : __DIR__"qiushuan",
		"east" : __DIR__"zuijing",
		"north": __DIR__"yimen",
		"south": __DIR__"shuwu",
	]));
	set("objects", ([
		CLASS_D("murong")+"/first" : 1,
	]));
	set("coor/x", 820);
	set("coor/y", -1540);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}