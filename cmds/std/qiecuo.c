inherit F_CLEAN_UP;

int main(object me, string arg)
{
  return notify_fail("你要在掌门师尊面前才能切磋。\n");
}
int help(object me)
{
write(@help
 指令格式 : qiecuo <基本功>[.<绝招名>]

    侠客行的武功很多都有绝招，但第一次使用这些绝招前，你必须找到门
派的掌门人，向掌门人切磋过才能用，如：qiecuo force.powerup  你需要
足够的的门派忠诚度才可以向掌门人切磋武学。前三次切磋需要的忠诚度分
别为100点、400点、900点，之后需要的忠诚度固定为1600点。最早的忠诚
度可以在武馆询问陈有德，并与武馆内的本门弟子探讨武功来获取，之后可
以通过做三个本门任务来提高。

    连续完成一定次数的本门叛徒任务后，掌门师尊会给你一次向他切磋特
殊武功的机会，你可以用qiecuo * 指定某项基本技能，如 qiecuo parry
这项基本技能相应的特殊技能会得到提高！
help
);
 return 1;
}