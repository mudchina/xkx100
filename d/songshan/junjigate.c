// Room: /d/songshan/junjigate.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "峻极山门");
	set("long", @LONG
嵩山绝顶，古称“峻极”。极顶有一峻极禅院，本是佛教大寺，但
百年来却已成为嵩山派掌门人的住所。这里是峻极禅院山门，西上山路
可以到达封禅台。
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao6",
		"northup"   : __DIR__"qianting",
		"westup"    : __DIR__"shandao7",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/first" : 1,
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 850);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
