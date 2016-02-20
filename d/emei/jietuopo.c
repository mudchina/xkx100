//Room: jietuopo.c 解脱坡
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","解脱坡");
      set("long",@LONG
这里是峨嵋胜地解脱坡。坡下一座小桥，叫解脱桥。行人至此，坐桥上听
泉声甚美。当此良辰美景，心无芥蒂，心即解脱。坡上一座庵堂，东下一片密
林。桥下山溪向东流淌到报国寺的西面。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown"  : __DIR__"milin2",
          "westup"    : __DIR__"guanyintang",
      ]));
      set("objects",([ /* sizeof() == 1 */
          CLASS_D("emei")+"/guo" : 1,
      ]));
      set("outdoors", "emei");
	set("coor/x", -6060);
	set("coor/y", -1040);
	set("coor/z", 30);
	setup();
      replace_program(ROOM);
}