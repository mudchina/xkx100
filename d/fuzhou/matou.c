// Room: /d/fuzhou/matou.c
// Last Modified by winder on Sep. 20 2002

#include <ansi.h>
inherit RIVER;


void create()
{
	::create();
  set("short", "中洲码头");
  set("long", @LONG
这里是福州中洲码头，眼前闽江水(river) 波涛翻滚，船只穿梭来
往不断。这里有通往上游延平府的客船。
LONG );
  set("exits", ([
    "east" : __DIR__"zhongzhou",
  ]));
  set("no_clean_up", 0);
  set("outdoors", "fuzhou");
  set("coor/x", 1830);
  set("coor/y", -6340);
  set("coor/z", 0);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "江");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功
  set("busy_msg",       "只听得江面上隐隐传来：“别急嘛，这儿正忙着呐……”\n");
  set("come_msg_out",   "一艘客船缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n");
  set("come_msg_in",    "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n");
  set("wait_msg",       "岸边一艘客船上的老艄公说道：正等着你呢，上来吧。\n");
  set("leave_msg_out",  "艄公把踏脚板收了起来，摇起橹来，客船向上游驶去。\n");
  set("leave_msg_in",   "艄公把踏脚板收起来，说了一声“坐稳喽”，摇起橹来，客船向上游驶去。\n");
  set("item_desc/river", HIC "\n只见近岸处有一艘客船，也许大声喊("
                         HIY "yell" HIC ")一声船家(" HIY "boat" HIC
                        ")就\n能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏江而过。\n" NOR);
  set("boat_short", "客船");    
  set("boat_desc",  @LONG
这是一艘在闽江上航行的大客船，大概能载上那么百把个人。两边
十几个水手握着长长的桨，船尾一名六十多岁的老艄公把着橹。江面的
水非常清澈，两边的山峰险峻，苍翠的森林中时而传来野兽的嘶嚎。
LONG );
  set("to",         "/d/yanping/longjindu");  // 船的终点 /*   必选   */
  setup();
}
