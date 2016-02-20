//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
  set ("short", "白帝城");
  set ("long", @LONG
白帝城是三峡的起点，位于长江北岸草堂河口，座落在名为白帝山
的紫色丘陵上。它是一座美丽的山城。青葱的白帝山象一块浑然的翡翠，
红墙绿瓦的白帝庙掩映在绿树丛中。清晨，山城沐浴在绯红的霞光里，
好比在“彩云间”一样。白帝城自古有“诗城”之称。杜甫曾有诗云：
白帝城中云出门，白帝城下雨翻盆。高江急峡雷霆斗，古木苍藤日月昏。
李白、刘禹锡、陆游、范成大等都曾在这里留下足迹，写了许多脍炙人
口的诗篇。东边就是险峻的瞿塘峡了。
LONG);
	set("no_clean_up", 0);
	set("outdoors", "jiangling");
	set("exits", ([
                "east" : __DIR__"qutangxia",
                "north": __DIR__"shandao6",
	]));
  
	set("coor/x", -1520);
	set("coor/y", -2060);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
