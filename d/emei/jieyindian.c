//Room: jieyindian.c 接引殿
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","接引殿");
      set("long",@LONG
接引殿右边濒崖，是金钢嘴。崖下有一块巨石，形状似钟，故名「钟石」。
对面有一石，高耸十余丈，叫「仙人石」。由此向上仰攀即到万行庵，北下经
「八十四盘」至洗象池。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "northwest" : __DIR__"bashisipan3",
          "westup"    : __DIR__"wanxingan",
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6210);
	set("coor/y", -1130);
	set("coor/z", 170);
	setup();
      replace_program(ROOM);
}