//Room: /d/dali/jinzhihe.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","金汁河畔");
	set("long",@LONG
这里位处金汁河畔，原本建有一座地藏寺，如今寺院早废。唯有一座
石刻经幢(jingzhuang)半埋土中。此幢为方锥状，七层石雕。高约丈五尺，
基座为八角形的磐石，边上刻有莲花；层与层之间有界石。即是本层之盖
檐，又是上层之基石。
LONG);
	set("item_desc", ([
	   "jingzhuang" : "这是个稀世经幢，进去看看也不坏。\n",
	]));
	set("objects", ([
	   __DIR__"npc/seng": 2,
	]));
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"yanchi1",
	    "west"  : __DIR__"xiaojing",
	    "enter" : __DIR__"jingzhuang1",
	]));
	set("coor/x", -36000);
	set("coor/y", -70500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}