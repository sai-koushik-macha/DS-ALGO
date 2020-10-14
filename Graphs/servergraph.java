package jcg.ssowmya.demo.graphExample;
 
import java.util.*;
 
public class ServerGraph {
    private Map<ServerVertex, List> adjServerVertices;
    public ServerGraph() {
        adjServerVertices = new LinkedHashMap();
    }
    public Map<ServerVertex, List> getAdjServerVertices() {
        return adjServerVertices;
    }
 
    public void setAdjServerVertices(Map<ServerVertex, List> adjServerVertices) {
        this.adjServerVertices = adjServerVertices;
    }
    public List getAdjVerticesForServerVertex(ServerVertex serverVertex) {
        return adjServerVertices.get(serverVertex);
    }
    public void addServerVertex(ServerVertex serverVertex) {
        adjServerVertices.putIfAbsent(serverVertex,new ArrayList());
    }
    public void removeServerVertexByIpAddress(String ipAddress) {
        if(adjServerVertices.isEmpty())
            return;
        Optional serverVertexOptional = adjServerVertices.keySet().stream().filter(serverVertex -> ipAddress.equals(serverVertex.getServerConfig().getIpAddress())).findAny();
        if(!serverVertexOptional.isPresent())
            return;
        ServerVertex serverVertexToBeRemoved = serverVertexOptional.get();
        adjServerVertices.values().stream().forEach(serverVertexList-> {
            serverVertexList.remove(serverVertexToBeRemoved);
        });
        adjServerVertices.remove(serverVertexToBeRemoved);
    }
    public void addEdge(ServerEdge edge){
        adjServerVertices.get(edge.getStart()).add(edge.getEnd());
        adjServerVertices.get(edge.getEnd()).add(edge.getStart());
    }
 
    public void removeEdge(ServerEdge edge) {
        adjServerVertices.get(edge.getStart()).remove(edge.getEnd());
        adjServerVertices.get(edge.getEnd()).remove(edge.getStart());
    }
 
    public List depthFirstTraversal(ServerVertex root) {
        List visitedNodes = new ArrayList();
        Stack serverVertexStack = new Stack();
        serverVertexStack.push(root);
        while(!serverVertexStack.isEmpty()) {
            ServerVertex visitedElement = serverVertexStack.pop();
            if(!visitedNodes.contains(visitedElement)) {
                visitedNodes.add(visitedElement);
                for(ServerVertex sv:getAdjVerticesForServerVertex(visitedElement))
                    serverVertexStack.push(sv);
            }
        }
        return visitedNodes;
 
    }
    public List breadthFirstTraversal(ServerVertex root) {
        List visitedNodes = new ArrayList();
        Queue serverVertexQueue = new LinkedList();
        serverVertexQueue.add(root);
        visitedNodes.add(root);
        while(!serverVertexQueue.isEmpty()) {
            ServerVertex visitedElement = serverVertexQueue.poll();
            for(ServerVertex sv:getAdjVerticesForServerVertex(visitedElement))
                if(!visitedNodes.contains(sv)) {
                    visitedNodes.add(sv);
                    serverVertexQueue.add(sv);
            }
        }
        return visitedNodes;
 
    }
 
    @Override
    public String toString() {
        return "ServerGraph{" +
                "adjServerVertices=" + adjServerVertices +
                '}';
    }
}
