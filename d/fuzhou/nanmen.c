// Room: /d/fuzhou/nanmen.c
// Date: May 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "福州南门");
	set("long", @LONG
这里是福州南门。往南望，是一片平展的平原。一片低矮的小树，
夹杂着一片片甘蔗林、芭蕉林。一条平直的大道从林中通过，道边一列
列的荔枝树和龙眼树。
LONG );
	set("exits", ([
		"south" : __DIR__"zhongzhou",
		"north" : __DIR__"nanmendou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "fuzhou");
	set("coor/x", 1840);
	set("coor/y", -6330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
