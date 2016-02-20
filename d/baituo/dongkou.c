// Room: /d/baituo/dongkou.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "洞口");
	set("long", @LONG
山贼的老窝的洞口藏在藤蔓之下，看起来有点阴森。洞口有一条石
砌就的门面，铺上木板，勉强算个门。往常时光，都有两个贼伙持刀护
卫，守备森严。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"dongnei",
		"south" : __DIR__"xiaolu4",
	]));
	set("objects",([
		__DIR__"npc/shanzei2" : 2,
	]));
	set("coor/x", -49960);
	set("coor/y", 20030);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
