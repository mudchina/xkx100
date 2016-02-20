//Room: fuzhenguan.c 复真观五层楼
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","复真观五层楼");
      set("long",@LONG
复真观五层楼构造奇特，其间有十二根梁枋交叉重叠，下面仅用一
柱支撑，即有名的“一柱十二梁”。在这里俯瞰群山，烟云迷离，远望
金顶，一柱擎天，为观景胜地。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "west"     : __DIR__"taizipo",
      ]));
      set("objects",([ /* sizeof() == 1 */
          "/clone/medicine/vegetable/mahuang" : random(2),
      ]));
      set("outdoors", "wudang");
	set("coor/x", -2040);
	set("coor/y", -860);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}
