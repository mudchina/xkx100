//  Room:  /d/luoyang/xiaojie1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "石街");
	set("long",  @LONG
洛阳是历代皇帝之都，规模宏伟，市肆却不甚繁华。你信步走进这
条小街，两边商店的门扇又黑又暗，出入其中的，大多衣裳滥褛，显见
这里是很大众化的街市。北面是个小酒馆。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"xiaojie2",
		"south" :  __DIR__"eastroad",
		"north" :  __DIR__"xiaojiudian",
	]));
	set("objects",  ([
		"/d/city/npc/liumang" : 3,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -400);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
