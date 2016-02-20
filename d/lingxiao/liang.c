// Room: /d/lingxiao/liang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","居室");
	set("long",@LONG
这是梁自进的房间，他生性单纯，与廖自励正好相反。他从小就在
凌霄城中练功习武，连大雪山也未下过一步，所以他的武功在五代弟子
中，是仅次于白自在的。他的房间朴素自然，仅有一床一桌。除此之外，
别无他物。 
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north" : __DIR__"zoulang3", 
	]));
	set("objects", ([
		__DIR__"npc/liang" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

