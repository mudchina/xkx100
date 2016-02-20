//Room: wnadian.c 万年庵砖殿
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","万年庵砖殿");
      set("long",@LONG
这里是万年庵的拱顶无梁砖殿。砖殿四壁为正方形，顶为穹窿圆拱形，殿
内有普贤菩萨骑六牙白象的铜铸像一尊。拱顶无梁砖殿四壁下方，有小龛二十
四个，内各供铁铸佛像一尊。四壁上方则有横龛六道，列置铜铸小佛三百零七
个。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/kong" : 1,
           CLASS_D("emei") + "/wenfang" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "east"    : __DIR__"wnachanfang",
          "out"     : __DIR__"wannianan",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6130);
	set("coor/y", -1060);
	set("coor/z", 60);
	setup();
      replace_program(ROOM);
}