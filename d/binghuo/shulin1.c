// Room: /binghuo/shulin1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "大树林");
	set("long", @LONG
这里绿树成荫。奇花异卉，长青阔叶，漫山遍野。在这极北之处，
居然有此林木，看来是拜火山之赐了。偶尔惊起一些叫不出名目的大
鸟小兽，也不避人。
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"haitan",
		"north"  : __DIR__"shulin2",
	]));
	setup();
	replace_program(ROOM);
}

