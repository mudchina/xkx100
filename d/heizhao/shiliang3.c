// Room: /heizhao/shiliang3.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "石梁");
	set("long", @LONG
石梁凹凸不平，又加终年在云雾之中，石上溜滑异常，走得越
慢，反是越易倾跌。石梁到这里忽然中断，约有七八尺长的一个缺
口，缺口彼端盘膝坐着一个书生，手中拿了一卷书，正自朗诵。那
书生身后又有一个短短的缺口。缺口那边一片荷塘边上婆娑摇曳着
一排棕榈
LONG );
	set("outdoors", "taoyuan");
	set("no_fight", 1);
	set("objects", ([
		CLASS_D("dali")+"/yideng/du" : 1,
	]));
	set("exits", ([
		"south"  : __DIR__"shiliang2",
		"north"  : __DIR__"hetang",
	]));
	set("coor/x", -5020);
	set("coor/y", -1230);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}