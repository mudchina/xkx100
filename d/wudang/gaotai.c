//Room: gaotai.c 南岩宫高台
//Date: Sep 29 1997

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short","南岩宫高台");
      set("long",@LONG
这里是就是南岩宫高台。高台孤悬崖侧，四望临渊，深不可测。山
风夹耳，松清涤面，顿觉心窍大开。
    武当真武剑阵就在这里。真武剑阵由五名五行弟子按东西南北中的
木、金、火、水、土方位，八名八卦弟子按乾、坤、坎、离、巽、震、
艮、兑八方天、地、水、火、风、雷、山、泽排列。
LONG);
      set("objects", ([
           CLASS_D("wudang") +"/wuxing": 5,
           CLASS_D("wudang") +"/bagua": 8,
           CLASS_D("wudang") +"/yan": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown" : __DIR__"nanyangong",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -970);
	set("coor/z", 100);
	setup();
      replace_program(ROOM);
}
