// Room: /d/lingxiao/zoulang3.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","走廊");
	set("long",@LONG 
这是一条安静的走廊，少有闲人走动，凌霄城四位五代长老就居住
在此周围。四老不喜花雪，是以深居此处。但听说由于六代弟子中白万
剑最为出色，甚至隐隐有压倒四位长老之势。四老心中不喜，已不收弟
子。
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"north"     : __DIR__"liao",  
		"south"     : __DIR__"liang", 
		"southeast" : __DIR__"houyuan2", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -31010);
	set("coor/y", -8840);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

