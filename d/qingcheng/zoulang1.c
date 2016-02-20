// Room: /qingcheng/zoulang1.c
// Date: Aug. 10 1998 by Winder

inherit ROOM;
void create()
{
	set("short", "松风走廊");
	set("long", @LONG
这里是松风观中连贯前殿后院的走廊，松风观高矗山顶，从走廊望
去，青山鸟寂，幽谷风生，漫天薄雾时时弥散在长林翠竹之间。自古号
称：“青城天下幽”，不妨在此体味。
LONG );
	set("outdoors", "qingcheng");
	set("exits", ([
		"south" : __DIR__"zhongmen",
		"north" : __DIR__"caochang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8080);
	set("coor/y", -850);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}