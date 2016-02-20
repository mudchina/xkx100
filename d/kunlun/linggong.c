// Room: /d/kunlun/linggong.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"灵獒宫"NOR);
	set("long", @LONG
你来到一座大厅之外，只见厅上扁额上写着“灵獒宫”三个血红大
字。一进厅，你便吃了一惊，但见三十余头雄健猛恶的大犬，分成三排
蹲在地上，一个身穿白孤裘的女郎坐在一张虎皮椅上，她手执皮鞭，正
在指挥恶犬咬人。南边是一个大院子。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"hmszhouyuan",
	]));
	set("objects",([
		__DIR__"npc/goupu" :  1,
		__DIR__"npc/dog"   :  1,
		__DIR__"npc/dog1"  :  1,
		__DIR__"npc/dog2"  :  1,
		__DIR__"npc/dog3"  :  1,
	]));
	set("coor/x", -90020);
	set("coor/y", 10030);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
