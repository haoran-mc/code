package cn.edu.ncu;

public class BeanFactory {
    public static UserService getUserService() {
        return new UserService();
    }

    public CategoryService getCategoryService() {
        return new CategoryService();
    }
}
