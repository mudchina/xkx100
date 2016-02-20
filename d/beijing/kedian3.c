inherit ROOM;

void create()
{
	set("short", "东客房");
	set("long", @LONG
一进门，只见六个喇嘛手持戒刀，围着一白衣女尼拼命砍杀，
只是给白衣女尼的袖力掌风逼住了，欺不近身。但那白衣女子头顶
已冒出丝丝白气，显然已尽了全力。她只一条臂膀，再支持下去恐
怕难以抵敌。地上斑斑点点都是血迹。
LONG );
	set("exits", ([
		"west" : __DIR__"kedian2",
	]));
	set("objects", ([
		__DIR__"npc/dubi" : 1,
		__DIR__"npc/lama" : 6,
	]));
	set("coor/x", -210);
	set("coor/y", 3990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

