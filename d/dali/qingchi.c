//Room: /d/dali/qingchi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","清池");
	set("long",@LONG
在这里你能享受到城内少有的清净。清池建于南诏年间，后有修
复，在大宋园林工匠的帮助下，更添姿彩。池内鱼虾龟虫倒也养了不
少，在这四季如春的气候下，荷花睡莲无比妖娆。
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"sheguta",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40020);
	set("coor/y", -71010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}