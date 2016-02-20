// Room: /d/yanping/jiusi.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "酒肆");
	set("long", @LONG
酒店门口一个酒招子半拉子挂着，店主人老蔡却不见了。两间茅屋
的小店显得十分空落，只有一个青袍年轻汉子靠在酒炉上，一双眼睛冷
冷地瞧着你。
LONG );
	set("exits", ([
		"south"     : __DIR__"guandao1",
	]));
        set("objects", ([
		"/d/qingcheng/npc/yuyan" : 1,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1700);
	set("coor/y", -6290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
