// Room: /d/lingxiao/laolang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "监狱走廊");
	set("long", @LONG
这是凌霄城监狱的走廊，两边关的都是凌霄城犯了门规的弟子。此
处地下高低不平，两边都是巨石筑成，一旦被关进来，就别想逃得出去。
墙上点着一支支火把，火光照得四周墙上的影子象要择人而噬的怪物一
样，看起来这种地方还是快走比较好。
LONG );
	set("exits", ([
		"up" : __DIR__"jianyuting",
		"west" : __DIR__"jianyusun",
		"east" : __DIR__"jianyuzhu",
		"down" : __DIR__"didi",
	]));
	set("objects", ([ 
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -30990);
	set("coor/y", -8900);
	set("coor/z", 130);
	setup(); 
	replace_program(ROOM);
}

