// Room: /d/kunlun/hmsznuange.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"暖阁"NOR);
	set("long", @LONG
昆仑山中一向极为寒冷，但在此暖阁之中却温暖如春，可又不见何
处生着炭火，此间取暖方法当真巧妙无比。阁中陈设辉煌灿烂，榻上椅
上都铺着锦缎软垫，极是富丽豪华。南边是大厅。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"hmszdating",
	]));
	set("objects",([
		__DIR__"npc/zhu1"   : 1,
		__DIR__"npc/yahuan" : 1,
	]));
	set("coor/x", -90030);
	set("coor/y", 10030);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
