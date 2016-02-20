// Room: /d/huanghe/dukou2.c
// Last Modified by winder on Apr. 10 2000
#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
    set("short", "龙门渡口");
    set("long", @LONG
渡口前就是汹涌澎湃的黄河(he)了。浊流滚滚，泥沙俱下，声震数
里。两岸渡船来来往往，在波谷中穿行，甚为凶险。过了黄河，对面就
是山西了。
LONG );
    set("exits", ([
        "southwest" : "/d/huanghe/weifen",
    ]));
    set("item_desc", ([
        "he" : "一叶小舟摇摆不定地顶风前行，喊(yell)一声试看。\n",
    ]));
    set("no_clean_up", 0);
    set("outdoors", "heimuya");
	set("coor/x", -1500);
	set("coor/y", 2000);
	set("coor/z", 0);
  set("yell_about", "船家");             // yell 船家
  set("river_type", "河");               // 江面上传来回响
  set("need_dodge",300);                 // 需要多少轻功
  set("come_msg_out",   "一叶扁舟缓缓地驶了过来，艄公将一块踏脚板搭上堤岸，以便乘客上下。\n");
  set("busy_msg",       "只听得风浪中隐隐传来：“别急嘛，这儿正忙着呐……”\n");
  set("wait_msg",       "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n");
  set("leave_msg_out",  "艄公把踏脚板收了起来，竹篙一点，扁舟向河中撑去。\n");
  set("leave_msg_in",   "艄公把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向河中撑去。\n");
  set("come_msg_in",    "艄公说“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n");
  set("item_desc/river", HIC "\n只见一叶小舟摇摆不定地顶风前行，也许大声喊("
                         HIY "yell" HIC ")一声船家(" HIY "boat" HIC
                        ")就\n能听见。倘若你自负轻功绝佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏河而过。\n" NOR);
  set("boat_short", "渡船");    
  set("boat_desc",  @LONG
黄河上的小舟都是这种很简陋的小舟。一位中年艄公正站在船尾
吃力地掌舵，一位膀子壮硕的小伙子也在船头用劲地划水撑船。黄河
水流湍急，船下滑很快，横渡却很慢。
LONG );
  set("to",         "/d/heimuya/dukou1");  // 船的终点 /*   必选   */
	setup();
}
