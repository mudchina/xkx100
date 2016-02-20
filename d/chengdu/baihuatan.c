// Room: /d/chengdu/baihuatan.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "百花潭");
	set("long", @LONG
潭面平静得象一块明晃晃的镜子，倒映着红瓦绿树；潭面的几片荷
叶，又给潭水增添了几分姿色。
LONG	);
	set("outdoors","chengdu");
	set("exits", ([		
		"northeast" : __DIR__"path4",				
		"north"     : __DIR__"caotang",				
	]));
	set("objects" , ([
		__DIR__"npc/youke" : 2,
	]));
	set("coor/x", -8090);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

