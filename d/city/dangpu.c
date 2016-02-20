// Room: /city/dangpu.c
// Last Modifyed by Winder on Dec. 12 2001

#include <ansi.h>
inherit ROOM;

int do_quit();
void create()
{
	set("short", "广陵当铺");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，
柜台上摆着一个牌子 (paizi)，柜台后坐着唐老板，一双精明的眼睛上上
下下打量着你。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : HIY"
┏━━━━━━━━━ "HIR"公平交易"HIY" ━━━━━━━━━┓
┃  ┌───────────────────┐  ┃
┃  │                                      │  ┃
┃  │  sell    ：卖                        │  ┃
┃  │  buy     : 买                        │  ┃
┃  │  redeem  : 赎                        │  ┃
┃  │  value   : 估价                      │  ┃
┃  │  list    : 看货                      │  ┃
┃  │        list armor    看防具类货物    │  ┃
┃  │        list weapon   看兵器类货物    │  ┃
┃  │        list book     看书籍类货物    │  ┃
┃  │        list medicine 看药品类货物    │  ┃
┃  │        list food     看食品类货物    │  ┃
┃  │        list liquid   看饮品类货物    │  ┃
┃  │        list fruit    看果品类货物    │  ┃
┃  │        list other    看其他类货物    │  ┃
┃  │                                      │  ┃
┃  └───────────────────┘  ┃
┗━━━━━━━━━━━━━━━━━━━━━━━┛
"NOR,
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"shilijie2",
	]));

	set("coor/x", 0);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
