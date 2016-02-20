//Room: hcazhaitang.c 华藏庵斋堂
//Date: Oct. 2 1997 by That

inherit ROOM;
string* names = ({
        __DIR__"obj/mala-doufu",
        __DIR__"obj/bocai-fentiao",
        __DIR__"obj/shanhu-baicai",
        __DIR__"obj/liuli-qiezi",
});

void create()
{
      set("short","华藏庵斋堂");
      set("long",@LONG
这里便是峨嵋华藏庵的斋堂。斋堂里摆满了长长的餐桌和长凳，几位小
师太正来回忙碌着布置素斋。桌上摆了几盆豆腐，花生，青菜以及素鸭等美
味素食。斋堂后面有一道门通往华藏庵储物间，北边的走廊通向广场。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"chuwujian", 
          "north" : __DIR__"hcaeast2", 
      ]));

      set("objects",([
           __DIR__"obj/qingshui-hulu" : 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6190);
	set("coor/y", -1190);
	set("coor/z", 190);
	setup();
      replace_program(ROOM);
}