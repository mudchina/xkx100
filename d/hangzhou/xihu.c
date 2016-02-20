// Room: /d/hangzhou/xihu.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "西湖");
	set("long",@LONG
西湖之仙姿丽质，引无数骚人墨客浅吟低唱：“未能抛得杭州去，
一半勾留是西湖”。孤山峙立湖面，如一朵绿色花冠。苏堤、白堤如两
条绿缎，飘逸于湛湛碧水之中。湖中三岛象三座海上仙山，鼎立湖心。
远望山峦，云山逶迤，雾霭漫漫。近观湖水，微波荡漾，波光粼粼。湖
边繁花如锦，绿荫中亭台楼榭时隐时现。
    苏子诗云：“水光潋滟晴方好，山色空朦雨亦奇，欲把西湖比西子，
淡妆浓抹总相宜。”
LONG );
	set("outdoors", "xihu");
	set("no_clean_up", 0);
	set("coor/x", 4120);
	set("coor/y", -1440);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
